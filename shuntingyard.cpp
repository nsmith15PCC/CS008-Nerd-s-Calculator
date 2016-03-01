#include "shuntingyard.h"

shuntingyard::shuntingyard()
{

}

queue<token> shuntingyard::makeRPN (queue<token> infixq)
{
    stack<token> op_stack;
    queue<token> rpnq;

    while (!infixq.empty())
    {
        token o1 = infixq.front();
        infixq.pop();
        if (o1.isOperator())
        {
            if (o1.op() == '(')
                op_stack.push(o1);
            else if (o1.op() == ')')
            {
                while (op_stack.top().op()!= '(')
                {
                    rpnq.push(op_stack.top());
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else
            {
                while (op_stack.empty() && op_stack.top() <= o1)
                {
                    rpnq.push(op_stack.top());
                    op_stack.pop();
                }
                op_stack.push(o1);
            }
        }
        else
        {
            rpnq.push(o1);
        }
    }
    while (!op_stack.empty())
    {
        rpnq.push(op_stack.top());
        op_stack.pop();
    }
    return rpnq;
}

static mixed calculate (queue<token> rpnq){}
