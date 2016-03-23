    #include "token.h"

const bool& token::isOperator() const
{
    return Operator;
}


bool& token::isOperator()
{
    return Operator;
}

token::token(const mixed &other)
{
*this = other;
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

token::token(const token &other)
{
    thevalue = other.thevalue;
    theOp = other.theOp;
    Operator = other.Operator;
}

token& token::operator=(const char &other)
{
    theOp = other;
    Operator = true;
    thevalue = mixed();
}

token& token::operator=(const mixed &other)
{
    thevalue = other;
    theOp = NULL;
    Operator = false;
    return*this;
}

token& token::operator=(const token &other)
{
    if (this != &other)
    {
    thevalue = other.thevalue;
    theOp = other.theOp;
    Operator = other.Operator;
    }
    return *this;
}

token& token::operator=(const fraction &other)
{
    thevalue = other;
    theOp = NULL;
    Operator = false;
    return*this;
}

token& token::operator=(const double &other)
{
    thevalue = other;
    theOp = NULL;
    Operator = false;
    return*this;
}

token& token::operator=(const int &other)
{
    thevalue = other;
    theOp = NULL;
    Operator = false;
    return*this;
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
    allOps['('] = &token::parentheses;

    allPriorities['+'] = 1;
    allPriorities['-'] = 1;
    allPriorities['*'] = 2;
    allPriorities['/'] = 2;
    allPriorities['^'] = 3;
    allPriorities['('] = 0;
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

token token::parentheses (const token &x, const token &y)
{
    try
    {
        throw MISSING_RIGHT_PARENTHESES;
    }
    catch (TOKEN_ERRORS e)
    {
        cout << "Missing parentheses!\n";
        exit(0);
    }
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
    if (line.find_first_of("0123456789") != string::npos)
    {
        mixed m;
        ss << line;
        ss >> m;
        t = m;
    }
    else
    {
        t = line[0];
    }
    return in;

}
