#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "shuntingyard.h"

using namespace std;

int main()
{

    queue<token> infixq, otherq;
    token a(5), b('*'), c(1.25);
    shuntingyard yard;

    infixq.push(a);
    infixq.push(b);
    infixq.push(c);

    cout<<infixq<<endl;


    return 0;

}
