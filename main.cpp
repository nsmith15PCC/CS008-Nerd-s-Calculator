#include <iostream>
#include <fstream>

#include "mixed.h"
#include "stack.h"
#include "queue.h"
#include "parser.h"
#include "shuntingyard.h"
#include "memory.h"
#include "instruction.h"

using namespace std;

void capitalizeString(string &line);


int main()
{
    string line;
    memory mem;
    instruction instruct;

    cout<<"Please enter expression: ";
    getline(cin, line);

    while (line!="")
    {
        capitalizeString(line);
        if(line.find("EXIT") < string::npos || line.find("QUIT") < string::npos
                || line.find("LOAD") < string::npos || line.find("READ") < string::npos
                || line.find("CLEAR") < string::npos || line.find("WRITE") < string::npos)
        {
            if(instruct.perform(line, mem))
                return 0;
        }
        else
            {
                if (line.find('=') != string::npos)
                    mem.store(line);
                else
                {
                    line = mem.replaceVars(line);
                     parser p;
                     try{
                    p.feed(line);
                    cout<<shuntingyard::calculate(shuntingyard::makeRPN(p.getQue()))<<endl;
                     }
                    catch (...)
                    {cout<<"Invalid Expression!"<<endl;}
                }
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


