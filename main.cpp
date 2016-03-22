#include <iostream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "parser.h"
#include "shuntingyard.h"
#include "memory.h"

using namespace std;

void capitalizeString(string &line);
bool checkInstruction(string line);

int main()
{
    string line;
    memory mem;
    cout<<"Please enter expression: ";
    getline(cin, line);

    while (line!="")
    {
        capitalizeString(line);
        if(checkInstruction(line))
            return 0;

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

void capitalizeString(string &line)
{
    for(int i = 0; i < line.length(); ++i)
    {
        if(line[i] > 96 && line[i] < 123)
            line[i] -= 32;
    }
}

bool checkInstruction(string line)
{
    if(line.find("EXIT") < string::npos|| line.find("QUIT") < string::npos)
        return true;
}
