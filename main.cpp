#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "parser.h"
#include "shuntingyard.h"
#include "memory.h"

using namespace std;

int main()
{
    string line;
    memory mem;
    cout<<"Please enter expression: ";
    getline(cin, line);

    while (line!="")
    {
        if (line.find('=') != string::npos)
            mem.store(line);
        else
        {
            line = mem.replaceVars(line);
             parser p;
            p.feed(line);
            cout<<shuntingyard::calculate(shuntingyard::makeRPN(p.getQue()))<<endl;
        }
        cout<<"Please enter expression: ";
        getline(cin, line);

    }

    return 0;
}
// Adding stuff!
