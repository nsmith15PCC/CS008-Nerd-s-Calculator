#ifndef NODE
#define NODE
#include <iostream>
#include <cstdlib>
#include "basenode.h"

using std::ostream;
using std::istream;
using std::endl;

template<typename value_type>
class node : public baseNode
{
public:
    typedef value_type* whatkind;



    node(const value_type &v = value_type(), baseNode* N = NULL, baseNode* P = NULL);
    ~node();
    node(const node<value_type> &other);

    node& operator=(const node<value_type> &other);
    
    void set_value (const value_type &new_value);

    value_type& get_value ();

    const value_type& get_value () const;
    
    template <typename D>
    friend
    std::ostream& operator<<(std::ostream& out, node<D> theNode);
    
    template <typename D>
    friend
    std::istream& operator>>(std::istream& in, node<D> theNode);
    
private:
    value_type value;
    void copy (const node<value_type> &other);
};

template<typename value_type>
node<value_type>::node(const value_type &v, baseNode* N, baseNode* P)
{
    value = v;
    next = N;
    prev = P;
}


template<typename value_type>
node<value_type>::~node<value_type>()
{
    value = value_type();
    next = prev = NULL;
}

template <typename value_type>
node<value_type>::node(const node<value_type> &other)
{
    copy (other);
}

template <typename value_type>
node<value_type>& node<value_type>::operator=(const node<value_type> &other)
{
    if (this != &other)
        copy (other);
    return *this;
}

template <typename value_type>
void node<value_type>::set_value (const value_type &new_value)
{
    value = new_value;
}

template <typename value_type>
value_type& node<value_type>::get_value()
{
    return value;
}

template <typename value_type>
const value_type& node<value_type>::get_value() const
{
    return value;
}

template <typename D>
ostream& operator<<(ostream& out, node<D> theNode)
{
    out << theNode.value;
    return out;
}

template <typename D>
istream& operator>>(istream& in, node<D> theNode)
{
    in >> theNode.value;
    return in;
}

template <typename value_type>
void node<value_type>::copy (const node<value_type> &other)
{
    value = other.get_value();
    prev = next = NULL;
}

#endif // NODE
