#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "shuntingyard.h"

using namespace std;

int main()
{

    queue<token> infixq;
    token a(5), b('*'), c(3);

    infixq.push(a);
    infixq.push(b);
    infixq.push(c);

    cout<<infixq;

    cout<<"Hello World!"<<endl;

    return 0;

}
