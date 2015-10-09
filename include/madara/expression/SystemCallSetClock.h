/* -*- C++ -*- */
#ifndef _MADARA_SYSTEM_CALL_SET_CLOCK_H_
#define _MADARA_SYSTEM_CALL_SET_CLOCK_H_

#ifndef _MADARA_NO_KARL_

#include <string>
#include <stdexcept>
#include "madara/utility/stdint.h"
#include "madara/expression/SystemCallNode.h"


namespace madara
{
  namespace expression
  {
    // Forward declaration.
    class Visitor;

    /**
     * @class SystemCallSetClock
     * @brief Sets the system clock or a variable clock
     */
    class SystemCallSetClock : public SystemCallNode
    {
    public:
      /**
       * Constructor
       **/
      SystemCallSetClock (
        madara::knowledge::ThreadSafeContext & context,
        const ComponentNodes & nodes);
      
      /**
       * Destructor
       **/
      virtual ~SystemCallSetClock (void);

      /**
       * Returns the value of the node
       * @return    value of the node
       **/
      virtual madara::KnowledgeRecord item (void) const;

      /** 
       * Prunes the expression tree of unnecessary nodes. 
       * @param     can_change   set to true if variable nodes are contained
       * @return    value of current contained expression tree
       **/
      virtual madara::KnowledgeRecord prune (bool & can_change);

      /** 
       * Evaluates the expression tree. 
       * @return    value of current contained expression tree
       **/
      virtual madara::KnowledgeRecord evaluate (
        const madara::knowledge::KnowledgeUpdateSettings & settings);

      /** 
       * Accepts a visitor subclassed from the Visitor class
       * @param    visitor   visitor instance to use
       **/
      virtual void accept (Visitor &visitor) const;
    };
  }
}

#endif // _MADARA_NO_KARL_

#endif /* _MADARA_SYSTEM_CALL_SET_CLOCK_H_ */