#include "linkedlist.h"

linkedList::linkedList()
{
    head = tail = NULL;
    qty = 0;
}

linkedList::~linkedList()
{
    nukem();
}

bool linkedList::empty()
{
    return !qty;
}

void linkedList::clear()
{
    nukem();
}

size_t linkedList::size()
{
    return qty;
}

void linkedList::insert_at_head (baseNode* newNode)
{
    newNode->set_next(head);
    if (head)
        head->set_prev(newNode);
    head = newNode;
    if (!tail)
        tail = head;
    ++qty;
}

void linkedList::insert_at_tail(baseNode *newNode)
{
    newNode->set_prev(tail);
    if (tail)
        tail->set_next(newNode);
    tail=newNode;
    if (!head)
        head = tail;
    ++qty;
}

void linkedList::insert_after(baseNode *afterthis, baseNode *insertthis)
{
    insertthis->set_next(afterthis->get_next());
    insertthis->set_prev(afterthis);
    afterthis->set_next(insertthis);
    qty++;
}

void linkedList::insert_before(baseNode *beforethis, baseNode *insertthis)
{
    insertthis->set_prev(beforethis->get_prev());
    insertthis->set_next(beforethis);
    beforethis->set_prev(insertthis);
    qty++;
}

void linkedList::remove_from_head()
{
    if (tail==head)
        tail = NULL;
    head = head->get_next();
    if (head)
        head->set_prev(NULL);
    --qty;
}

void linkedList::remove_from_tail()
{
    if (tail==head)
        head = NULL;
    tail = tail->get_prev();
    if (tail)
        tail->set_next(NULL);
    --qty;
}

void linkedList::remove(baseNode *whom)
{
    baseNode *prev = whom->get_prev(), *next = whom->get_next();
    prev->set_next(next);
    next->set_prev(prev);
    --qty;
}


void linkedList::nukem()
{
    while (head)
        remove_from_head();
    tail = NULL;
    qty = 0;
}
