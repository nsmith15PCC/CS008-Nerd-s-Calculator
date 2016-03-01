#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "shuntingyard.h"

using namespace std;

queue<token> makeRPN (queue<token> infixq);

stack<token> copyqueue (queue<token> other);


int main()
{

    queue<token> infixq, rpnq;
    token a('('), b(5), c('+'), d(3), e(')'), f('*'), g(7);
    shuntingyard yard;

//    infixq.push(a);
    infixq.push(b);
    infixq.push(c);
    infixq.push(d);
//    infixq.push(e);
    infixq.push(f);
    infixq.push(g);



    rpnq = makeRPN(infixq);

    cout<<infixq<<endl;

    cout<<rpnq<<endl;

    return 0;
}

stack<token> copyqueue (queue<token> other)
{
    stack<token> x;
    while (!other.empty())
    {
        x.push(other.front());
        other.pop();
    }
    return x;
}


queue<token> makeRPN (queue<token> infixq)
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
