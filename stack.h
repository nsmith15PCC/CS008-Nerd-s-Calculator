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
    ostream& operator<<(ostream& out, const stack<D> &theStack);

    template<typename D>
    friend
    istream& operator>>(istream& in, stack<D> &theStack);

private:
    void copy (const stack<value_type> &other);
};

template <typename value_type>
stack<value_type>::stack()
{
    head = tail = NULL;
    qty = 0;
}

template <typename value_type>
stack<value_type>::~stack()
{
while(head)
    pop();
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
    node<value_type> *ptr = (node<value_type>*)head;
    remove_from_head();
    delete ptr;
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
    while (head)
        pop();


    for (node<value_type> *ptr = (node<value_type>*)other.head; ptr; ptr = (node<value_type>*)ptr->get_next())
    {
        node<value_type> *newNode = new node<value_type>(*ptr);
        insert_at_tail(newNode);
    }
}

template<typename D>
ostream& operator<<(ostream& out, const stack<D> &theStack)
{
    for (node<D> *ptr = (node<D>*)theStack.head;
         ptr;
         ptr = (node<D>*)ptr->get_next())
         out<<(*ptr)<<' ';
    out<<"\b ";

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

