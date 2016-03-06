#include "memory.h"

enum MEMORY_ERRORS{NO_KEY};

memory::memory()
{
    values = map<char,mixed>();
    it = values.begin();
}

memory::~memory()
{

}

memory::memory(const memory &other)
{
    values = other.values;
    it = values.begin();
}

memory& memory::operator=(const memory &other)
{
    if (this != &other)
    {
        values = other.values;
        it = values.begin();
    }
    return *this;
}

mixed& memory::setValue(char index)
{
    return values[index];
}

const mixed& memory::getValue(char index) const
{
    map<char,mixed>::const_iterator it = values.find(index);
    if (it == values.end())
        throw NO_KEY;
    else
        return it->second;
}

string memory::replaceVars(string input)
{
    size_t i(0);
    while (i < input.size())
    {
        while (isalpha(input[i]))
        {
            stringstream ss;
            char index = input[i];
            ss<<input.substr(0,i)<<' '<<getValue(index)<<' '<<input.substr(i+1);
//            std::cout<<input.substr(0,i)<<' '<<getValue(index)<<' '<<input.substr(i+1)<<std::endl;
            std::getline(ss, input);
        }
        ++i;
    }
//    std::cout << input<<std::endl;
    return input;
}

bool memory::store(string input)
{
    size_t pos = input.find('=');
    stringstream ss;
    char index;
    string expression;

    ss << input.substr(0,pos);
    ss >> index;

    if (values.find(index) != values.end())
    {
        string answer;
        std::cout<<"Variable "<<index<<" currently holds value "<<values[index]<<endl
                   <<"Overwrite? ";
        std::getline(std::cin, answer);
        if (toupper(answer[0]) != 'Y')
            return false;
    }

    input = input.substr(pos+1);

    input = replaceVars(input);

    parser p(input);
    queue<token> infixq = p.getQue(), rpnq = shuntingyard::makeRPN(infixq);
    values[index] = shuntingyard::calculate(rpnq);
    cout<<index<<" = "<<values[index]<<endl;
    return true;
}


ostream& operator<<(ostream& out, const memory &m)
{
    for (map<char,mixed>::const_iterator it= m.values.begin(); it != m.values.end(); ++it)
        out<<it->first<<" = "<<it->second<<endl;
    return out;
}

istream& operator>>(istream& in, memory &m)
{
    string input;
    while (std::getline(in, input))
    {
        m.store(input);
    }
}
