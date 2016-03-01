#include "operand.h"

operand::operand(mixed v)
{
    thevalue = v;
    isOperator() = false;
}

operand::operand(const double &other)
{
    *this = other;
}

operand::operand(const int &other)
{
    *this = other;
}

operand::operand(const fraction &other)
{
    *this = other;
}

operand& operand::operator=(const fraction &other)
{
    thevalue = other;
    return *this;
}

operand& operand::operator=(const double &other)
{
    thevalue = other;
    return *this;
}

operand& operand::operator=(const int &other)
{
    thevalue = other;
    return *this;
}

mixed& operand::value ()
{
    return thevalue;
}

const mixed& operand::value () const
{
    return thevalue;
}
