#ifndef BASENODE
#define BASENODE
#include <iostream>

class baseNode
{
public:
    baseNode();
    ~baseNode();
    baseNode(const baseNode &other);
    baseNode& operator=(const baseNode &other);
    
    void set_next(baseNode* new_next);
    void set_prev(baseNode* new_prev);
    
    baseNode* get_next();
    const baseNode* get_next() const;
    
    baseNode* get_prev();
    const baseNode* get_prev() const;
    
protected:
    baseNode *next, *prev;
};

#endif // BASENODE
