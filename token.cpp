#include "token.h"

const bool& token::isOperator() const
{
    return Operator;
}


bool& token::isOperator()
{
    return Operator;
}

token::token(mixed v)
{
    thevalue = v;
    theOp = NULL;
    isOperator() = false;
}

token::token(const double &other)
{
    *this = other;
}

token::token(const int &other)
{
    *this = other;
}

token::token(const fraction &other)
{
    *this = other;
}

token& token::operator=(const char &other)
{
    theOp = other;
    isOperator() = true;
    thevalue = mixed();
}

token& token::operator=(const fraction &other)
{
    thevalue = other;
    return *this;
}

token& token::operator=(const double &other)
{
    thevalue = other;
    return *this;
}

token& token::operator=(const int &other)
{
    thevalue = other;
    return *this;
}

mixed& token::value ()
{
    return thevalue;
}

const mixed& token::value () const
{
    return thevalue;
}


token::func_ptr token::allOps[] = {NULL};
int token::allPriorities[] = {0};

token::token(char o)
{
    *this = o;

    allOps['+'] = &token::add;
    allOps['-'] = &token::subtract;
    allOps['*'] = &token::times;
    allOps['/'] = &token::divide;
    allOps['^'] = &token::power;

    allPriorities['+'] = 1;
    allPriorities['-'] = 1;
    allPriorities['*'] = 2;
    allPriorities['/'] = 2;
    allPriorities['^'] = 3;
    allPriorities['('] = 4;
    allPriorities[')'] = 4;
}

char& token::op()
{
    return theOp;
}

const char& token::op() const
{
    return theOp;
}

token token::perform(const token &x, const token &y)
{
    return (*allOps[theOp])(x, y);
}

token token::add (const token &x, const token &y)
{
    return token(x.value() + y.value());
}

token token::subtract (const token &x, const token &y)
{
    return token(x.value() - y.value());
}

token token::times (const token &x, const token &y)
{
    return token(x.value() * y.value());
}

token token::divide (const token &x, const token &y)
{
    return token(x.value() / y.value());
}

token token::power (const token &x, const token &y)
{
    return token(x.value() ^ y.value());
}

bool operator<(const token x, const token y)
{
    return (x.allPriorities[x.theOp] < y.allPriorities[y.theOp]);
}

bool operator>(const token x, const token y)
{
    return (x.allPriorities[x.theOp] > y.allPriorities[y.theOp]);
}

bool operator<=(const token x, const token y)
{
    return (x.allPriorities[x.theOp] <= y.allPriorities[y.theOp]);
}

bool operator>=(const token x, const token y)
{
    return (x.allPriorities[x.theOp] >= y.allPriorities[y.theOp]);
}

bool operator==(const token x, const token y)
{
    return (x.allPriorities[x.theOp] == y.allPriorities[y.theOp]);
}

bool operator!=(const token x, const token y)
{
    return (x.allPriorities[x.theOp] != y.allPriorities[y.theOp]);
}


std::ostream& operator<<(std::ostream& out, const token &t)
{
    if (t.Operator)
        out<<t.theOp;
    else
        out<<t.thevalue;
    return out;
}


std::istream& operator>>(std::istream& in, token &t)
{
    std::string line;
    std::stringstream ss;
    getline(in, line);
    if (isdigit(line[0]))
    {
        mixed m;
        ss << line;
        ss >> m;
        t = m;
    }
    else
    {
        char c;
        ss << line;
        ss.get(c);
        t = c;
    }
    return in;

}
