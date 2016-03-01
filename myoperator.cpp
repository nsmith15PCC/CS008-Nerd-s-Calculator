#include "myoperator.h"
#include "operand.h"
#include "mixed.h"

myoperator::func_ptr myoperator::allOps[] = {NULL};
int myoperator::allPriorities[] = {0};

myoperator::myoperator(char o)
{
theOp = o;
isOperator() = true;

allOps['+'] = &myoperator::add;
allOps['-'] = &myoperator::subtract;
allOps['*'] = &myoperator::times;
allOps['/'] = &myoperator::divide;
allOps['^'] = &myoperator::power;

allPriorities['+'] = 1;
allPriorities['-'] = 1;
allPriorities['*'] = 2;
allPriorities['/'] = 2;
allPriorities['^'] = 3;
allPriorities['('] = 4;
allPriorities[')'] = 4;
}

char& myoperator::op()
{
    return theOp;
}

const char& myoperator::op() const
{
    return theOp;
}

operand myoperator::perform(const operand &x, const operand &y)
{
    return (*allOps[theOp])(x, y);
}

operand myoperator::add (const operand &x, const operand &y)
{
    return operand(x.value() + y.value());
}

operand myoperator::subtract (const operand &x, const operand &y)
{
    return operand(x.value() - y.value());
}

operand myoperator::times (const operand &x, const operand &y)
{
    return operand(x.value() * y.value());
}

operand myoperator::divide (const operand &x, const operand &y)
{
    return operand(x.value() / y.value());
}

operand myoperator::power (const operand &x, const operand &y)
{
    return operand(x.value() ^ y.value());
}

bool operator<(const myoperator x, const myoperator y)
{
    return (x.allPriorities[x.theOp] < y.allPriorities[y.theOp]);
}

bool operator>(const myoperator x, const myoperator y)
    {
        return (x.allPriorities[x.theOp] > y.allPriorities[y.theOp]);
    }

bool operator<=(const myoperator x, const myoperator y)
{
    return (x.allPriorities[x.theOp] <= y.allPriorities[y.theOp]);
}

bool operator>=(const myoperator x, const myoperator y)
{
    return (x.allPriorities[x.theOp] >= y.allPriorities[y.theOp]);
}

bool operator==(const myoperator x, const myoperator y)
{
    return (x.allPriorities[x.theOp] == y.allPriorities[y.theOp]);
}

bool operator!=(const myoperator x, const myoperator y)
{
    return (x.allPriorities[x.theOp] != y.allPriorities[y.theOp]);
}
