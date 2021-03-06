/*********************************************************************
* Copyright (c) 2013-2015 Carnegie Mellon University. All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following acknowledgments and disclaimers.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* 3. The names "Carnegie Mellon University," "SEI" and/or
* "Software Engineering Institute" shall not be used to endorse or promote
* products derived from this software without prior written permission. For
* written permission, please contact permission@sei.cmu.edu.
*
* 4. Products derived from this software may not be called "SEI" nor may "SEI"
* appear in their names without prior written permission of
* permission@sei.cmu.edu.
*
* 5. Redistributions of any form whatsoever must retain the following
* acknowledgment:
*
* This material is based upon work funded and supported by the Department of
* Defense under Contract No. FA8721-05-C-0003 with Carnegie Mellon University
* for the operation of the Software Engineering Institute, a federally funded
* research and development center. Any opinions, findings and conclusions or
* recommendations expressed in this material are those of the author(s) and
* do not necessarily reflect the views of the United States Department of
* Defense.
*
* NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING
* INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. CARNEGIE MELLON
* UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR IMPLIED,
* AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF FITNESS FOR
* PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS OBTAINED FROM USE OF THE
* MATERIAL. CARNEGIE MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND
* WITH RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
*
* This material has been approved for public release and unlimited
* distribution.
*
* @author Amit S <amitmsurana@gmail.com>
*********************************************************************/

#include "ai_madara_filters_compression_LZ4BufferFilter.h"
#include "madara_jni.h"

#include "madara/filters/lz4/LZ4BufferFilter.h"

#ifdef  _USE_LZ4_
namespace filters = madara::filters;
typedef  filters::LZ4BufferFilter LZ4BufferFilter;
#endif 

/*
 * Class:     ai_madara_filters_compression_LZ4BufferFilter
 * Method:    jni_Lz4BufferFilter
 * Signature: ()J
 */
jlong JNICALL Java_ai_madara_filters_compression_LZ4BufferFilter_jni_1Lz4BufferFilter__
  (JNIEnv *env, jobject){

  jlong result (0);

#ifndef _USE_LZ4_
  madara::utility::java::throw_feature_not_impl_exception(env,
       "LZ4BufferFilter::constructor: "
       "MADARA library does not support LZ4");
  return result;
#endif

#ifdef _USE_LZ4_
  result = (jlong) new LZ4BufferFilter ();
#endif

  return result;
}

/*
 * Class:     ai_madara_filters_compression_LZ4BufferFilter
 * Method:    jni_Lz4BufferFilter
 * Signature: (J)J
 */
jlong JNICALL Java_ai_madara_filters_compression_LZ4BufferFilter_jni_1Lz4BufferFilter__J
  (JNIEnv *env, jobject, jlong cptr){

  jlong result (0);

#ifndef _USE_LZ4_
  madara::utility::java::throw_feature_not_impl_exception(env,
       "LZ4BufferFilter::constructor: "
       "MADARA library does not support LZ4");
  return result;
#endif

#ifdef _USE_LZ4_
  LZ4BufferFilter * input = (LZ4BufferFilter *)cptr;
  if (input != 0)
  {
    result = (jlong) new LZ4BufferFilter (*input);
  }
  else
  {
    // user has tried to use a deleted object. Clean up and throw
  
    madara::utility::java::throw_dead_obj_exception(env,
      "LZ4BufferFilter::copyConstructor: "
      "LZ4BufferFilter object is released already");
  }
#else
  (void)env; (void)cptr;
#endif

  return result;

}

/*
 * Class:     ai_madara_filters_compression_LZ4BufferFilter
 * Method:    jni_freeLz4BufferFilter
 * Signature: (J)V
 */
void JNICALL Java_ai_madara_filters_compression_LZ4BufferFilter_jni_1freeLz4BufferFilter
  (JNIEnv *, jclass, jlong cptr){
  #ifdef _USE_LZ4_
  LZ4BufferFilter * current = (LZ4BufferFilter *)cptr;
  delete current;
#else
  (void)cptr;
#endif
}

/*
 * Class:     ai_madara_filters_compression_LZ4BufferFilter
 * Method:    jni_encode
 * Signature: (J[BJJ)J
 */
jlong JNICALL Java_ai_madara_filters_compression_LZ4BufferFilter_jni_1encode
(JNIEnv * env, jobject, jlong cptr, jbyteArray buffer, jlong size, jlong max_size){

  jlong result (size);

#ifdef _USE_LZ4_
  LZ4BufferFilter * current = (LZ4BufferFilter *)cptr;

  if (current)
  {
    char * elements = (char *)env->GetByteArrayElements (
      buffer, 0);

    result = current->encode (elements, size, max_size);

    env->ReleaseByteArrayElements (buffer, (jbyte *)elements, 0);
  }
  else
  {
    // user has tried to use a deleted object. Clean up and throw
  
    madara::utility::java::throw_dead_obj_exception(env,
      "LZ4BufferFilter::encode: "
      "LZ4BufferFilter object is released already");
  }

#else
  (void)env; (void)cptr; (void)buffer; (void)size; (void)max_size;
#endif

  return result;
}

/*
 * Class:     ai_madara_filters_compression_LZ4BufferFilter
 * Method:    jni_decode
 * Signature: (J[BJJ)J
 */
 jlong JNICALL Java_ai_madara_filters_compression_LZ4BufferFilter_jni_1decode
(JNIEnv * env, jobject, jlong cptr, jbyteArray buffer, jlong size, jlong max_size){

  jlong result (size);

#ifdef _USE_LZ4_
  LZ4BufferFilter * current = (LZ4BufferFilter *)cptr;

  if (current)
  {
    char * elements = (char *)env->GetByteArrayElements (
      buffer, 0);

    result = current->decode (elements, size, max_size);

    env->ReleaseByteArrayElements (buffer, (jbyte *)elements, 0);
  }
  else
  {
    // user has tried to use a deleted object. Clean up and throw
  
    madara::utility::java::throw_dead_obj_exception(env,
      "LZ4BufferFilter::decode: "
      "LZ4BufferFilter object is released already");
  }


#else
  (void)env; (void)cptr; (void)buffer; (void)size; (void)max_size;
#endif

  return result;

}


