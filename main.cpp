#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "parser.h"
#include "shuntingyard.h"

using namespace std;

int main()
{
    queue<token> infixq, rpnq;
    parser p;
    shuntingyard yard;
    p.feed(" ( 5 * ( 8 + 4 ) )");

    infixq = p.getQue();

    cout<<infixq<<endl;

    rpnq = shuntingyard::makeRPN(infixq);

    cout<<rpnq<<endl;

    cout<<shuntingyard::calculate(rpnq)<<endl;

    return 0;
}

