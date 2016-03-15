#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <cstdlib>

#include "node.h"

class linkedList
{
public:
    linkedList();
    virtual ~linkedList();

    bool empty();
    void clear();

    size_t size();

    void insert_at_head (baseNode* newNode);

    void insert_at_tail (baseNode* newNode);

    void insert_after (baseNode* afterthis, baseNode* insertthis);

    void insert_before (baseNode* beforethis, baseNode* insertthis);

    void remove_from_head();

    void remove_from_tail();

    void remove (baseNode* whom);

protected:
    baseNode *head, *tail;
    size_t qty;
    void nukem();
};

#endif // LINKEDLIST

