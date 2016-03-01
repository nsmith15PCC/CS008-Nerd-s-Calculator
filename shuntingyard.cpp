#include "shuntingyard.h"

shuntingyard::shuntingyard(){}

queue<token> shuntingyard::makeRPN (const queue<token> &other)
{
    queue<token> infixq = other;
    stack<token> op_stack;
    queue<token> rpnq;

    while (!infixq.empty())
    {
        token *o1 = &infixq.front();
        infixq.pop();
        if (o1->isOperator())
        {
            token *myop = (token*)(o1);
            if (myop->op() == '(')
                op_stack.push(token(*myop));
            else if (myop->op() == ')')
            {
                while (op_stack.top().op()!= '(')
                {
                    rpnq.push(token(op_stack.top()));
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else
            {
                while (op_stack.empty() && op_stack.top() <= *myop)
                {
                    rpnq.push(token(op_stack.top()));
                    op_stack.pop();
                }
                op_stack.push(token(*myop));
            }
        }
        else
        {
            token* myop = (token*)o1;
            rpnq.push(token(*myop));
            infixq.pop();
        }
    }
    while (!op_stack.empty())
    {
        rpnq.push(token(op_stack.top()));
        op_stack.pop();
    }
    return rpnq;
}

static mixed calculate (queue<token> rpnq){}
