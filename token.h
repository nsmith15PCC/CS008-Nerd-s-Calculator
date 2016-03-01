#ifndef TOKEN
#define TOKEN
#include "mixed.h"

class token
{
public:
    const bool& isOperator() const;
    bool& isOperator();


protected:
    char theOp;
    mixed thevalue;

private:
    bool Operator;
};

#endif // TOKEN

