#include "parser.h"

parser::parser()
{
    nQue = queue<token>();
}

parser::parser(string line)
{
    feed(line);
}

parser::~parser()
{
    nukem();
}

void parser::feed(string line)
{
    stringstream ss;
    mixed num;
    token op;

    while(int pos = line.find_first_of("/*-+^()") < line.length())
    {
        if(line[pos] == '(' || line[pos] == ')')
        {
            cout << "( or ) case!\n";
            ss << line[pos];
            ss >> op;
            nQue.push(op);
            ss.flush();
            line = line.substr(pos+1);
        }
        else if(line[pos] == '/' && (line[pos-1] != ' ' || line[pos+1 ]!= ' '))
        {
            cout << "fraction / case!\n";
        }
        else
        {
            cout << "normal case!\n";
            ss << line.substr(0,pos-1);
            cout << "NUMSTART\n";
            ss >> num;
            cout << "NUMFINE\n";
            nQue.push(num);
            ss.flush();
            ss << line[pos];
            ss>>op;
            nQue.push(op);
            ss.flush();
            line = line.substr(pos+1);
            cout << "normal case successful!\n";
        }
    }
}

queue<token>& parser::getQue()
{
    return nQue;
}

const queue<token>& parser::getQue() const
{
    return nQue;
}


void parser::nukem()
{
    nQue = queue<token>();
}
