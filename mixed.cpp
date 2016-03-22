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
    if (number.setdecimal())
    {
        cout << (double)number.numerator()/number.denominator();
        return out;
    }
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
    int w=0, n, d=1;
    double c;
    stringstream ss;
    char junk;
    string line;

    getline(in,line);
    ss << line;

    if (line.find('.')<string::npos)
    {
        ss >> c;
        number = c;
        return in;
    }

    size_t first_num, space, second_num, slash;

    first_num = line.find_first_of("0123456789");

    space = line.find(' ', first_num+1);

    second_num = line.find_first_of("0123456789", space);

    slash = line.find('/', first_num);

    if (space>first_num && second_num != string::npos)
    {
        ss >> w >> n >> junk >> d;
        cout << "w = " << w << endl << "n = " << n << endl << "d = " << d << endl;
    }

    else if (slash != string::npos)
    {
        ss >> n >> junk >> d;
    }

    else
    {
        ss >> n;
    }

    number = mixed(w, n, d);

    return in;
}
