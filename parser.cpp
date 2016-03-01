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

    size_t pos1 = 0, pos2;


    while (pos1 < line.length())
    {
        pos2 = line.find_first_of("/*-+^()",pos1+1);
        if ((line[pos2] == '/' || line[pos2] == '-')&&isdigit(line[pos2+1]))
            pos2 = line.find_first_of("/*-+^()",pos2+1);
        if (pos2 == string::npos)
            pos2 = line.length();

        ss<< line.substr(pos1, pos2-pos1);
        cout<<pos1<<' '<<pos2<<" Substring: "<<line.substr(pos1, pos2-pos1)<<endl;
        ss >> num;
        op = num;
        nQue.push(op);

        if (pos2 < line.length())
        {
            op = line[pos2];
            nQue.push(op);
        }
        pos1 = pos2+1;
    }
}


//    while(int pos = line.find_first_of("/*-+^()") < line.length())
//    {
//        if(line[pos] == '(' || line[pos] == ')')
//        {
//            cout << "( or ) case!\n";
//            ss << line[pos];
//            ss >> op;
//            nQue.push(op);
//            ss.flush();
//            line = line.substr(pos+1);
//        }
//        else if(line[pos] == '/' && (line[pos-1] != ' ' || line[pos+1 ]!= ' '))
//        {
//            cout << "fraction / case!\n";
//        }
//        else
//        {
//            cout << "normal case!\n";
//            ss << line.substr(0,pos);
//            cout << line.substr(0,pos);
//            cout << "NUMSTART\n";
//            ss >> num;
//            cout << "NUMFINE\n";
//            nQue.push(num);
//            ss.flush();
//            ss << line[pos];
//            ss>>op;
//            nQue.push(op);
//            ss.flush();
//            line = line.substr(pos+1);
//            cout << "normal case successful!\n";
//        }
//    }


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
