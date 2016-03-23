#include "parser.h"

enum PARSER_ERRORS{INVALID_CHARACTER};

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
////Parser by Nate
//    size_t pos1 = 0, pos2;
//    line = " "+line;

//    while (pos1 < line.length())
//    {
//        stringstream ss;
//        mixed num;
//        token op;
//        pos2 = line.find_first_of("/*-+^()",pos1);
//        if ((line[pos2] == '/' || line[pos2] == '-')&&isdigit(line[pos2+1]))
//            pos2 = line.find_first_of("/*-+^()",pos2+1);
//        if (pos2 == string::npos)
//            pos2 = line.length();
//        if(line.substr(pos1, pos2-pos1)!= " " && line.substr(pos1, pos2-pos1)!= "")
//        {
//            ss<< line.substr(pos1, pos2-pos1);
//            ss >> num;
//           cout << "num = " << num << endl;
//            op = num;
//            nQue.push(op);
//        }

//        if (pos2 < line.length())
//        {
//            op = line[pos2];
//            nQue.push(op);
//        }
//        pos1 = pos2+1;
//    }

// Parser by Hyun
    size_t pos = 0;
    stringstream ss;
    mixed num;
    token op;

    line += " ";

//    try
//    {
        if(line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890()^*/-+. ") < string::npos)
            throw INVALID_CHARACTER;
//    }
//    catch (PARSER_ERRORS e)
//    {
//        cout << "Invalid character used for calculator!\n";
//        exit(0);
//    }

    while(pos < line.length()-1)
    {
        pos = line.find_first_of("/*-+^()", pos);

        if(pos >= string::npos)
        {
            pos = line.length();
            ss << line.substr(0,pos);
            ss >> num;
            ss.clear();
            op = num;
            nQue.push(op);
        }
        else if(line[pos+1] == ' ' || line[pos+1] == '(' || isdigit(line[pos+1]))
        {
            if(line.substr(0,pos).find_first_not_of(" ") < string::npos)
            {
                ss << line.substr(0,pos);
                ss >> num;
                ss.clear();
                op = num;
                nQue.push(op);
            }
            op = line[pos];
            if(op == '(' && line[pos-1] == '-')
            {
                nQue.push(token(-1));
                nQue.push(token('*'));
            }
            nQue.push(op);
            line = line.substr(pos+1);
            pos = 0;
        }
        else
        {
            pos = pos+1;
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
