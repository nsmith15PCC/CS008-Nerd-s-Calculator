#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "parser.h"
#include "shuntingyard.h"

using namespace std;

int main()
{
    string line;
    cout<<"Please enter expression: ";
    getline(cin, line);

    while (line!="")
    {
    queue<token> infixq, rpnq;
    parser p;
    shuntingyard yard;
    p.feed(line);

    infixq = p.getQue();

    cout<<"Entered: "<<line<<endl;

    cout<<"Infix: "<<infixq<<endl;

    rpnq = shuntingyard::makeRPN(infixq);//Something

    cout<<"Postfix: "<<rpnq<<endl;

    cout<<"Evaluates to: "<<shuntingyard::calculate(rpnq)<<endl;

    cout<<"Please enter expression: ";
    getline(cin, line);
    }

    return 0;
}

