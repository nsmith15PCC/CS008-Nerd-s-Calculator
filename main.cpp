#include <iostream>
#include "myoperator.h"
#include "operand.h"
#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "shuntingyard.h"

using namespace std;

int main()
{
    operand a(3), b(2);
    myoperator x('+'), y('*');
    queue<token> infixq, rpnq;
    shuntingyard here;

    infixq.push(a);
    infixq.push(x);
    infixq.push(b);




    while (!infixq.empty())
    {
        if (infixq.front().isOperator())
        { myoperator *ptr = (myoperator*)&infixq.front();
            cout<< ptr->op()<<endl;
        }
        else
        {
            operand *ptr = (operand*)&infixq.front();
            cout<<ptr->value()<<endl;
        }
        infixq.pop();
    }

//    rpnq = here.makeRPN(infixq);


    while (!rpnq.empty())
    {
        if (rpnq.front().isOperator())
        { myoperator *ptr = (myoperator*)&rpnq.front();
            cout<< ptr->op()<<endl;
        }
        else
        {
            operand *ptr = (operand*)&rpnq.front();
            cout<<ptr->value()<<endl;
        }
        rpnq.pop();
    }



    return 0;

}
