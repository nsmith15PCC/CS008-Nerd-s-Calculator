#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "shuntingyard.h"

using namespace std;

queue<token> makeRPN (const queue<token> &other);


int main()
{

    queue<token> infixq, rpnq;
    token a(5), b('*'), c(3);
    shuntingyard yard;

    infixq.push(a);
    infixq.push(b);
    infixq.push(c);

    rpnq = infixq;

    cout << infixq;

    //error in makeRPN. Currently taking a look into this. I believe line 60 is the cause.
    cout<<makeRPN(rpnq);


    return 0;
}

queue<token> makeRPN (const queue<token> &other)
{
    queue<token> infixq = other;
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
                //The code below causes error, as if it is empty, there is no top, returning a NULL?
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
        cout << "infixq qty = " << infixq.size() << std::endl;
    }

    while (!op_stack.empty())
    {
        rpnq.push(op_stack.top());
        op_stack.pop();
    }
    return rpnq;
}
