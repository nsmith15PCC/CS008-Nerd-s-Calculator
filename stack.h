#ifndef STACK
#define STACK
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "node.h"
#include "linkedlist.h"

using std::ostream;
using std::string;
using std::stringstream;
using std::istream;
using std::endl;

template <typename value_type>
class stack : public linkedList
{
public:
    stack();
    ~stack();
    stack(const stack<value_type> &other);

    stack& operator=(const stack<value_type> &other);

    void pop();

    value_type& top();

    const value_type& top() const;

    void push(const value_type &new_value);

    template<typename D>
    friend
    ostream& operator<<(ostream& out, stack<D> &theStack);

    template<typename D>
    friend
    istream& operator>>(istream& in, stack<D> &theStack);

private:
    void copy (const stack<value_type> &other);
};

template <typename value_type>
stack<value_type>::stack()
{
    head = NULL;
}

template <typename value_type>
stack<value_type>::~stack()
{
    nukem();
}

template <typename value_type>
stack<value_type>::stack(const stack<value_type> &other)
{
    copy(other);
}

template <typename value_type>
stack<value_type>& stack<value_type>::operator=(const stack &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

template <typename value_type>
void stack<value_type>::pop()
{
    remove_from_head();
}

template <typename value_type>
value_type& stack<value_type>::top()
{
    node<value_type> *ptr = (node<value_type>*)head;
    return(ptr->get_value());
}

template <typename value_type>
const value_type& stack<value_type>::top() const
{
    node<value_type> *ptr = (node<value_type>*)head;
    return(ptr->get_value());
}

template <typename value_type>
void stack<value_type>::push(const value_type &new_value)
{
    node<value_type>* ptr = new node<value_type>(new_value);
    insert_at_head(ptr);
}

template <typename value_type>
void stack<value_type>::copy (const stack<value_type> &other)
{
    nukem();
    node<value_type> *ptr = (node<value_type>*)other.head;

    while (ptr)
    {
        insert_at_tail(new node<value_type>(*ptr));
        ptr = (node<value_type>*)ptr->get_next();
    }
}

template<typename D>
ostream& operator<<(ostream& out, stack<D> &theStack)
{
    for (node<D> *ptr = (node<D>*)theStack.head;
         ptr != NULL;
         ptr = (node<D>*)ptr->get_next())
         out<<(*ptr)<<endl;

    return out;
}

template<typename D>
istream& operator>>(istream& in, stack<D> &theStack)
{
    D thedata;
    while (in>>thedata)
    {
        node<D> *ptr = new node<D>(thedata);
        theStack.insert_at_tail(ptr);
    }
    return in;
}

#endif // STACK

