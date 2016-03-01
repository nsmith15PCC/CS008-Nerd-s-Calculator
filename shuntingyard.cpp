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
                while (op_stack.top().op() != '(')
                {
                    token o2 = op_stack.top();
                    rpnq.push(o2);
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else
            {
                while (!op_stack.empty() && (op_stack.top() > o1))
                {
                    token o2 = op_stack.top();
                    rpnq.push(o2);
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
        const token o2 = op_stack.top();
        rpnq.push(o2);
        op_stack.pop();
    }
    return rpnq;
}

mixed shuntingyard::calculate (queue<token> rpnq)
{
    stack<token> val_stack;

    while (!rpnq.empty())
    {
        token o1 = rpnq.front();
        rpnq.pop();

        if (o1.isOperator())
        {
            token second = val_stack.top();
            val_stack.pop();
            token first = val_stack.top();
            val_stack.pop();
            token answer = o1.perform(first,second);
            val_stack.push(answer);
        }
        else
            val_stack.push(o1);
    }

    return val_stack.top().value();
}
