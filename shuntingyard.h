#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <iostream>
#include "token.h"
#include "stack.h"
#include "queue.h"
#include "mixed.h"

class shuntingyard
{
public:

    typedef void (*func_ptr) (stack<token>&, token&);

    static func_ptr doOperation[2];

    shuntingyard();


    static queue<token> makeRPN (queue<token> infixq);

    static mixed calculate (queue<token> rpnq);

    static void doOperator(stack<token> &val_stack, token &o1);

    static void doOperand(stack<token> &val_stack, token &o1);

};

#endif // SHUNTINGYARD_H
