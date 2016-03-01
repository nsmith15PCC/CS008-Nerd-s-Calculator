#ifndef MYOPERATOR_H
#define MYOPERATOR_H
#include "token.h"
#include "mixed.h"
#include "operand.h"

class myoperator : public token
{
public:

    typedef operand (*func_ptr) (const operand&, const operand&);

    myoperator(char o = NULL);

    char& op();
    const char& op() const;

    unsigned short int priority() const;

    operand perform(const operand &x, const operand &y);



    friend
    bool operator<(const myoperator x, const myoperator y);

    friend
    bool operator>(const myoperator x, const myoperator y);

    friend
    bool operator<=(const myoperator x, const myoperator y);

    friend
    bool operator>=(const myoperator x, const myoperator y);

    friend
    bool operator==(const myoperator x, const myoperator y);

    friend
    bool operator!=(const myoperator x, const myoperator y);

private:
//    char theOp;

    static func_ptr allOps[128];
    static int allPriorities[128];

    static operand add (const operand &x, const operand &y);
    static operand subtract (const operand &x, const operand &y);
    static operand times (const operand &x, const operand &y);
    static operand divide (const operand &x, const operand &y);
    static operand power (const operand &x, const operand &y);

};

#endif // MYOPERATOR_H
