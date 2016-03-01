#ifndef QUEUE
#define QUEUE

#include "linkedlist.h"
#include <sstream>

using std::ostream;
using std::istream;
using std::stringstream;
using std::string;
using std::endl;

template <typename value_type>
class queue : public linkedList
{
public:
    queue();
    ~queue();
    queue(const queue<value_type> &other);

    queue& operator=(const queue<value_type> &other);

    void push(const value_type &new_value);

    void pop();

    value_type& front();
    value_type& back();

    const value_type& front() const;
    const value_type& back() const;


    template<typename T>
    friend
    istream& operator>>(istream& in, queue<T> q);

    friend
    istream& operator>>(istream& in, queue<string> q);

    template<typename T>
    friend
    ostream& operator<<(ostream& out, queue<T> q);

private:
    void copy (const queue<value_type> &other);
};

template <typename value_type>
queue<value_type>::queue()
{
head = tail = NULL;
qty = 0;
}

template <typename value_type>
queue<value_type>::~queue()
{
while (head)
{
    node<value_type> *ptr = (node<value_type>*)head;
    head = head->get_next();
    delete ptr;
}
}

template <typename value_type>
queue<value_type>::queue(const queue<value_type> &other)
{
    copy(other);
}

template <typename value_type>
queue<value_type>& queue<value_type>::operator=(const queue<value_type> &other)
{
    if (this != &other)
        copy(other);
    return *this;
}


template <typename value_type>
void queue<value_type>::push(const value_type &new_value)
{
    node<value_type> *ptr = new node<value_type>(new_value);
    insert_at_tail(ptr);
}


template <typename value_type>
void queue<value_type>::pop()
{
    node<value_type> *ptr = (node<value_type>*)head;
remove_from_head();
delete ptr;
}

template <typename value_type>
value_type& queue<value_type>::front()
{
    node<value_type> *ptr = (node<value_type>*)head;
    return ptr->get_value();
}

template <typename value_type>
value_type& queue<value_type>::back()
{
    node<value_type> *ptr = (node<value_type>*)tail;
    return ptr->get_value();
}


template <typename value_type>
const value_type& queue<value_type>::front() const
{
    node<value_type> *ptr = (node<value_type>*)head;
    return ptr->get_value();
}

template <typename value_type>
const value_type& queue<value_type>::back() const
{
    node<value_type> *ptr = (node<value_type>*)tail;
    return ptr->get_value();
}

template<typename T>
istream& operator>>(istream& in, queue<T> q)
{
    T holder;
    while (in>>holder)
        q.push(holder);
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, queue<T> q)
{
    for (node<T> *ptr = (node<T>*)q.head; ptr; ptr = (node<T>*)ptr->get_next())
        out<<ptr->get_value()<<endl;
    return out;
}


template <typename value_type>
void queue<value_type>::copy (const queue<value_type> &other)
{
    for (node<value_type> *ptr = (node<value_type>*)other.head; ptr; ptr = (node<value_type>*)ptr->get_next())
        push(ptr->get_value());
}

#endif // QUEUE

