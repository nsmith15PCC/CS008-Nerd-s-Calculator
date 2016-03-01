#include "basenode.h"

baseNode::baseNode()
{
    next = prev = NULL;
}

baseNode::~baseNode()
{
    next = prev = NULL;
}

baseNode::baseNode(const baseNode &other)
{
    next = prev = NULL;
}

baseNode& baseNode::operator=(const baseNode &other)
{
    next = prev = NULL;
}


void baseNode::set_next(baseNode* new_next)
{
    next = new_next;
}

void baseNode::set_prev(baseNode* new_prev)
{
    prev = new_prev;
}

baseNode* baseNode::get_next()
{
    return next;
}

const baseNode* baseNode::get_next() const
{
    return next;
}

baseNode* baseNode::get_prev()
{
    return prev;
}

const baseNode* baseNode::get_prev() const
{
    return prev;
}
