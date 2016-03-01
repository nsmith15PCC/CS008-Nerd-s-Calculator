#include "mixed.h"

mixed::mixed(int w, int n, int d)
{
    numerator() = w*d + n;
    denominator() = d;
    setdecimal() = false;
    reduce();
}

mixed::mixed(const fraction& x)
{
    numerator() = x.numerator();
    denominator() = x.denominator();
    setdecimal() = x.setdecimal();
}


mixed::mixed(int x)
{
    numerator() = x;
    denominator() = 1;
    setdecimal() = false;
}

mixed::mixed(double x)
{
    *this = fraction(x);
}

mixed::mixed(const mixed &x)
{
numerator() = x.numerator();
denominator() = x.denominator();
setdecimal() = x.setdecimal();
}

mixed::mixed(int x, const fraction &f)
{
    numerator() = x*f.denominator()+f.numerator();
    denominator() = f.denominator();
}

mixed& mixed::operator=(const mixed &other)
{
    if (this != &other)
    {
    numerator() = other.numerator();
    denominator() = other.denominator();
    setdecimal() = other.setdecimal();
    }
    return *this;
}


mixed& mixed::operator=(int x)
{
    numerator() = x;
    denominator() = 1;
    return *this;
}

mixed& mixed::operator=(double x)
{
    *this = fraction(x);
    return *this;
}

mixed& mixed::operator=(const fraction &x)
{
    numerator() = x.numerator();
    denominator() = x.denominator();
    setdecimal() = x.setdecimal();
    return *this;    
}

mixed::~mixed()
{
    numerator() = 0;
    denominator() = 1;
}

void mixed::value(int w, int n, int d)
{
    *this = mixed(w,n,d);
}

void mixed::value(double x)
{
    *this = x;
}
void mixed::value(const fraction &x)
{
    *this = x;
}

ostream& operator<<(ostream& out, const mixed &number)
{
    if (number.denominator() != 1)
    {
    if (abs(number.numerator())>=number.denominator())
        out<<(number.numerator()/number.denominator())<<' '<<abs((number.numerator()%number.denominator()))<<"/"<<number.denominator();
    else
        out<< number.numerator()<<'/'<<number.denominator();
    }
    else
       out<< number.numerator();
    return out;
}

istream& operator>>(istream& in, mixed &number)
{
    string line;
    fraction num, denom(1);
    in >> line;
    size_t space = line.find(' '), slash = line.find('/');
try{

    if (space != string::npos && slash != string::npos)
    {
        num = stod(line.substr(0,space)) * stod(line.substr(slash+1)) + stod(line.substr(space+1, slash));
        denom = stod(line.substr(slash+1));
    }
    else if (slash != string::npos)
    {
        num = stod(line.substr(0,slash));
        denom = stod(line.substr(slash+1));
    }
    else
        num = stod(line);
    number = num/denom;
    }
    catch(...)
    {
        cout<<line;
    }

    return in;
}
