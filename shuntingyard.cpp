#include "shuntingyard.h"

shuntingyard::shuntingyard(){}

queue<token> shuntingyard::makeRPN (queue<token> infixq)
{
    stack<myoperator> op_stack;
    queue<token> rpnq;

    while (!infixq.empty())
    {
        token *o1 = &infixq.front();
        infixq.pop();
        if (o1->isOperator())
        {
            myoperator *myop = (myoperator*)(o1);
            if (myop->op() == '(')
                op_stack.push(myoperator(*myop));
            else if (myop->op() == ')')
            {
                while (op_stack.top().op()!= '(')
                {
                    rpnq.push(myoperator(op_stack.top()));
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else
            {
                while (op_stack.empty() && op_stack.top() <= *myop)
                {
                    rpnq.push(myoperator(op_stack.top()));
                    op_stack.pop();
                }
                op_stack.push(myoperator(*myop));
            }
        }
        else
        {
            operand* myop = (operand*)o1;
            rpnq.push(operand(*myop));
            infixq.pop();
        }
    }
    while (!op_stack.empty())
    {
        rpnq.push(myoperator(op_stack.top()));
        op_stack.pop();
    }
    return rpnq;
}

static mixed calculate (queue<token> rpnq){}
