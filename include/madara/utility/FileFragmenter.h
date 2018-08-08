#ifndef _MADARA_UTILITY_FILEFRAGMENTER_H_
#define _MADARA_UTILITY_FILEFRAGMENTER_H_

#include <string>
#include <vector>
#include "madara/knowledge/KnowledgeRecord.h"
#include "madara/utility/Utility.h"
#include "madara/utility/ScopedArray.h"
#include "madara/knowledge/containers/Vector.h"
#include "madara/logger/GlobalLogger.h"

namespace madara
{
  namespace utility
  {
    /**
     * @class FileFragmenter
     * @brief Enforces a periodic epoch
     */
    class FileFragmenter
    {
    public:
      /**
       * Constructor
       * @param  buffer     the file contents
       * @param  size       the size of the buffer in bytes
       * @param  frag_size  the max size of fragments to create
       **/
      FileFragmenter (char * buffer, size_t size, size_t frag_size = 600000)
      {
        fragment_buffer (buffer, size, frag_size);
      }

      /**
       * Constructor
       * @param  filename   the file to read in and fragment
       * @param  frag_size  the max size of fragments to create
       **/
      FileFragmenter (const std::string & filename, size_t frag_size = 600000)
      {
        fragment_file (filename, frag_size);
      }

      /**
       * Fragments a file into smaller buffers up to a specified size
       * @param  filename   the file to read in and fragment
       * @param  frag_size  the max size of fragments to create
       * @return number of fragments that resulted
       * @return the number of fragments created
       **/
      inline size_t fragment_file (
        const std::string & filename, size_t frag_size = 600000)
      {
        void * buffer;

        if (utility::read_file (filename, buffer, file_size))
        {
          file_contents = (char *)buffer;
          return fragment_buffer (file_contents.get (), file_size, frag_size);
        }

        return 0;
      }

      /**
       * Fragments a file into smaller buffers up to a specified size
       * @param  buffer     the file contents
       * @param  size       the size of the buffer in bytes
       * @param  frag_size  the max size of fragments to create
       * @return the number of fragments created
       **/
      inline size_t fragment_buffer (char * buffer, size_t size,
        size_t frag_size = 600000)
      {
        size_t num_frags = size / frag_size;
        size_t extra = size % frag_size;
        utility::ScopedArray<unsigned char> segment =
          new unsigned char [frag_size];

        if (extra > 0)
        {
          records.resize (num_frags + 1);

          // copy over the extra chars to the last record
          memcpy (segment.get (), &(buffer[num_frags * frag_size]), extra);
          records[num_frags].set_file (segment.get (), extra);
        }
        else
        {
          records.resize (num_frags);
        }

        // need to then emplace each buffer into the records
        for (size_t i = 0; i < num_frags; ++i)
        {
          // copy over each segment of frag_size and emplace in record
          memcpy (segment.get (), &(buffer[i * frag_size]), frag_size);
          records[i].set_file (segment.get (), frag_size);
        }

        return records.size ();
      }

       /**
       * Creates a vector in a knowledge base with the current file fragments
       * @param  key     the location in the knowledge base to save to
       * @param  kb      the knowledge base to save to
       * @return a container that can reference the elements in the KB
       **/
      knowledge::containers::Vector create_vector (
        const std::string & key, knowledge::KnowledgeBase & kb)
      {
        knowledge::containers::Vector result (key, kb);
        
        for (size_t i = 0; i < records.size (); ++i)
          result.push_back (records[i]);

        return result;
      }

       /**
       * Creates a vector in a knowledge base with the current file fragments.
       * This method is useful to check file transfer progress through a KB.
       * @param  key     the location in the knowledge base to load from
       * @param  kb      the knowledge base to load from
       * @return the number of bytes currently in the KB Vector
       **/
      size_t from_kb (
        const std::string & key, knowledge::KnowledgeBase & kb)
      {
        file_size = 0;
        file_contents = 0;
        bool has_missing = false;
        knowledge::containers::Vector fragments (key, kb);
        
        fragments.copy_to (records);

        madara_logger_ptr_log (
          logger::global_logger.get(), logger::LOG_MAJOR,
          "FileFragmenter::from_kb:" \
          " iterating through each record in %d records at %s\n",
          (int)records.size (), key.c_str ());

        // go through the records and check for valid records
        for (auto record : records)
        {
          // if it's valid, add the size
          if (record.is_file_type ())
          {
            file_size += record.size ();
          }
          else
          {
            madara_logger_ptr_log (
              logger::global_logger.get(), logger::LOG_MAJOR,
              "FileFragmenter::from_kb:" \
              " missing fragment\n");

            has_missing = true;
          }
        }

        madara_logger_ptr_log (
          logger::global_logger.get(), logger::LOG_MAJOR,
          "FileFragmenter::from_kb:" \
          " after iterations, file_size=%d\n",
          (int)file_size);

        // if there are no missing fragments, copy everything to file_contents
        if (!has_missing)
        {
          file_contents = new char [file_size];
          char * current = file_contents.get ();

          // go through the records and check for valid records
          for (auto record : records)
          {
            // need to check on whether or not we need to try/catch here
            std::shared_ptr <const std::vector <unsigned char>> binary = 
              record.share_binary ();

            madara_logger_ptr_log (
              logger::global_logger.get(), logger::LOG_MINOR,
              "FileFragmenter::from_kb:" \
              " copying %d bytes to file_contents\n",
              (int)binary->size ());

            memcpy (current, binary->data (), record.size ());

            current += record.size ();

            madara_logger_ptr_log (
              logger::global_logger.get(), logger::LOG_DETAILED,
              "FileFragmenter::from_kb:" \
              " proceeding to next record copy\n");

          } // end for all records
        } // end not missing any file fragments
        else
        {
          madara_logger_ptr_log (
            logger::global_logger.get(), logger::LOG_MINOR,
            "FileFragmenter::from_kb:" \
            " missing fragments. Not rebuilding file_contents\n");

        }

        return file_size;
      }



      /// records that contain the file fragments
      knowledge::KnowledgeVector records;

      /// the size of the file contents
      size_t file_size;

      /// the buffer that holds the file contents
      utility::ScopedArray<char> file_contents;
    };
  }
}

#endif // _MADARA_UTILITY_FILEFRAGMENTER_H_
