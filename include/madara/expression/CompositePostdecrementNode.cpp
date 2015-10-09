/* -*- C++ -*- */
#ifndef _COMPOSITE_PREDECREMENT_NODE_CPP_
#define _COMPOSITE_PREDECREMENT_NODE_CPP_

#ifndef _MADARA_NO_KARL_

#include <iostream>

#include "madara/expression/ComponentNode.h"
#include "madara/expression/CompositeUnaryNode.h"
#include "madara/expression/Visitor.h"
#include "madara/expression/CompositePostdecrementNode.h"
#include "madara/expression/LeafNode.h"
#include "madara/expression/VariableNode.h"

madara::expression::CompositePostdecrementNode::CompositePostdecrementNode (
  logger::Logger & logger, ComponentNode *right)
: CompositeUnaryNode (logger, right)
{
  var_ = dynamic_cast <VariableNode *> (right);

  if (!var_)
    array_ = dynamic_cast <CompositeArrayReference *> (right);
}

// Dtor
madara::expression::CompositePostdecrementNode::~CompositePostdecrementNode (void)
{
}

madara::KnowledgeRecord
madara::expression::CompositePostdecrementNode::item (void) const
{
  madara::KnowledgeRecord record;
  record.set_value ("--");
  return record;
}

/// Prune the tree of unnecessary nodes. 
/// Returns evaluation of the node and sets can_change appropriately.
/// if this node can be changed, that means it shouldn't be pruned.
madara::KnowledgeRecord
madara::expression::CompositePostdecrementNode::prune (bool & can_change)
{
  bool right_child_can_change = false;
  madara::KnowledgeRecord right_value;

  if (this->right_)
  {
    right_value = this->right_->prune (right_child_can_change);
    if (!right_child_can_change && dynamic_cast <LeafNode *> (right_) == 0)
    {
      delete this->right_;
      this->right_ = new LeafNode (*(this->logger_), right_value);
    }
  }
  else
  {
    madara_logger_ptr_log (logger_, logger::LOG_EMERGENCY,
      "KARL COMPILE ERROR: Predecrement has no right expression\n");

    exit (-1);
  }

  can_change = right_child_can_change;

  return --right_value;
}

/// Evaluates the node and its children. This does not prune any of
/// the expression tree, and is much faster than the prune function
madara::KnowledgeRecord 
madara::expression::CompositePostdecrementNode::evaluate (
  const madara::knowledge::KnowledgeUpdateSettings & settings)
{
  madara::KnowledgeRecord return_value;

  if (var_)
  {
    return_value = var_->evaluate (settings);
    var_->dec (settings);
  }
  else if (array_)
  {
    return_value = array_->evaluate (settings);
    array_->dec (settings);
  }
  else
  {
    return_value = --(this->right_->evaluate (settings));
  }

  return return_value;
}

// accept a visitor
void 
madara::expression::CompositePostdecrementNode::accept (Visitor &visitor) const
{
  visitor.visit (*this);
}

#endif // _MADARA_NO_KARL_

#endif /* _COMPOSITE_PREDECREMENT_NODE_CPP_ */