#include "shuntingyard.h"

shuntingyard::func_ptr shuntingyard::doOperation[] = {nullptr};

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

                    if(op_stack.empty())
                        throw MISSING_LEFT_PARENTHESES;
                }
                op_stack.pop();
            }
            else
            {
                while (!op_stack.empty() && (op_stack.top() >= o1))
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

    doOperation[0] = &doOperand;
    doOperation[1] = &doOperator;

    while (!rpnq.empty())
    {
        token o1 = rpnq.front();
        rpnq.pop();

        //        try
        //        {
        (doOperation[o1.isOperator()])(val_stack, o1);
        //        }
        //        catch (SHUNTINGYARD_ERRORS e)
        //        {
        //            cout << "TOO MANY OPERATORS!\n";
        ////            exit(0);
        //        }

        //        if (o1.isOperator())
        //        {
        //            token second = val_stack.top();
        //            val_stack.pop();
        //            token first = val_stack.top();
        //            val_stack.pop();
        //            token answer = o1.perform(first,second);
        //            val_stack.push(answer);
        //        }
        //        else
        //            val_stack.push(o1);
    }

    if (val_stack.size() != 1)
    {
        cout<<"Stack Size = "<<val_stack.size()<<endl;
        cout << val_stack<<endl;
        throw XSOPERATORS;
    }

    return val_stack.top().value();
}

void shuntingyard::doOperator(stack<token> &val_stack, token &o1)
{
    if(val_stack.empty())
        throw XSOPERATORS;
    token second = val_stack.top();
    val_stack.pop();
    if(val_stack.empty())
        throw XSOPERATORS;
    token first = val_stack.top();
    val_stack.pop();
    token answer = o1.perform(first,second);
    val_stack.push(answer);
}

void shuntingyard::doOperand(stack<token> &val_stack, token &o1)
{
    val_stack.push(o1);
}
