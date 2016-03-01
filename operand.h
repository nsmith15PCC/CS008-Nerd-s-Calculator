#ifndef OPERAND_H
#define OPERAND_H
#include "token.h"
#include "mixed.h"


class operand : public token
{
public:
    operand(mixed v = mixed(0,0,1));
    operand(const double &other);
    operand(const int &other);
    operand(const fraction &other);

    operand& operator=(const fraction &other);
    operand& operator=(const double &other);
    operand& operator=(const int &other);

    mixed& value ();
    const mixed& value () const;

private:

};

#endif // OPERAND_H
