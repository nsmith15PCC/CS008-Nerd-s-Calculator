#include "fraction.h"

fraction::fraction(int n , int d )
{
    num = n;
    denom = d;
    decimal = false;
    reduce();
}

fraction::~fraction()
{
    num = 0;
    denom = 1;
}


fraction::fraction(const double &other)
{
    *this = other;
}

fraction::fraction(const fraction &other)
{
    *this = other;
}

fraction& fraction::operator=(const fraction &other)
{
    if (this != &other)
    {
        num = other.num;
        denom = other.denom;
        decimal = other.decimal;
    }
    return *this;
}

fraction& fraction::operator=(const int &other)
{
    num = other;
    denom = 1;
    decimal = false;
    return *this;
}

fraction& fraction::operator=(const double &other)
{
    int power = 1;
    while ( (power*abs(other) - (int)(power*abs(other))) > 0)
        power *= 10;
    num = (int)(power*other);
    denom = power;
    decimal = true;
    reduce();
    return *this;
}

void fraction::setValue(int n , int d )
{
    num = n;
    denom = d;
    decimal = false;
}

fraction& fraction::operator+=(const fraction &other)
{
    num = num*other.denom + other.num*denom;
    denom *= other.denom;
    decimal = decimal || other.decimal;
    reduce();
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    num = num*other.denom - other.num*denom;
    denom *= other.denom;
    decimal = decimal || other.decimal;
    reduce();
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    num *= other.num;
    denom *= other.denom;
    decimal = decimal || other.decimal;
    reduce();
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    num *= other.denom;
    denom *= other.num;
    decimal = decimal || other.decimal;
    reduce();
    return *this;
}

fraction& fraction::operator^=(const fraction &other)
{
double base = (double)(num)/denom;
double power = (double)(other.num)/other.denom;
*this = fraction(pow(base,power));
return *this;
}

fraction& fraction::operator+=(int other)
{
    *this += fraction(other);
    return *this;
}

fraction& fraction::operator-=(int other)
{
    *this -= fraction(other);
    return *this;
}

fraction& fraction::operator*=(int other)
{
    *this *= fraction(other);
return *this;
}

fraction& fraction::operator/=(int other)
{
    *this /= fraction(other);
    return *this;
}

fraction& fraction::operator^=(int other)
{
    double base = (double)(num)/denom;
    *this = pow(base, other);
    return *this;
}

fraction& fraction::operator+=(double other)
{
    *this += fraction(other);
    return *this;
}
fraction& fraction::operator-=(double other)
{
    *this -= fraction(other);
    return *this;
}
fraction& fraction::operator*=(double other)
{
    *this *= fraction(other);
    return *this;
}
fraction& fraction::operator/=(double other)
{
    *this /= fraction(other);
    return *this;
}
fraction& fraction::operator^=(double other)
{
    double base = (double)(num)/denom;
    *this = pow(base, other);
    return *this;
}

void fraction::reduce()
{
    int greatest = gcd(num, denom);
    num /= greatest;
    denom /= greatest;

    if (denom<0)
    {
        num *= -1;
        denom *= -1;
    }

    if (denom == 0)
        cout << "BAD BOY\n";
}

int& fraction::numerator()
{
    return num;
}
int& fraction::denominator()
{
    return denom;
}

bool &fraction::setdecimal()
{
    return decimal;
}

const int& fraction::numerator() const
{
    return num;
}
const int& fraction::denominator() const
{
    return denom;
}

const bool& fraction::setdecimal() const
{
    return decimal;
}

void fraction::copy(const fraction& other)
{
    num = other.num;
    denom = other.denom;
}

int fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q,p%q);
}


// Binary operations fraction to fraction

fraction operator+(const fraction &x, const fraction &y)
{
    fraction z(x.num*y.denom+y.num*x.denom, x.denom*y.denom);
    z.decimal = x.decimal || y.decimal;
    z.reduce();
    return z;
}

fraction operator-(const fraction &x, const fraction &y)
{
    fraction z(x.num*y.denom-y.num*x.denom, x.denom*y.denom);
    z.decimal = x.decimal || y.decimal;
    z.reduce();
    return z;
}

fraction operator*(const fraction &x, const fraction &y)
{
    fraction z(x.num*y.num, x.denom*y.denom);
    z.decimal = x.decimal || y.decimal;
    z.reduce();
    return z;
}

fraction operator/(const fraction &x, const fraction &y)
{
    fraction z(x.num*y.denom, x.denom*y.num);
    z.decimal = x.decimal || y.decimal;
    z.reduce();
    return z;
}

fraction operator^(const fraction &x, const fraction &y)
{
    double zdec = pow((double)(x.num)/x.denom, (double)(y.num)/y.denom);
    fraction z(zdec);
    z.reduce();
    return z;
}

bool operator==(const fraction &x, const fraction &y)
{
    return (x.num*y.denom == y.num*x.denom);
}

bool operator!=(const fraction &x, const fraction &y)
{
    return !(x.num*y.denom == y.num*x.denom);
}


bool operator<=(const fraction &x, const fraction &y)
{
        return (x.num*y.denom <= y.num*x.denom);
}


bool operator>=(const fraction &x, const fraction &y)
{
    return (x.num*y.denom >= y.num*x.denom);

}


bool operator<(const fraction &x, const fraction &y)
{
    return (x.num*y.denom < y.num*x.denom);
}


bool operator>(const fraction &x, const fraction &y)
{
    return (x.num*y.denom > y.num*x.denom);

}

// Binary operations fraction to int

bool operator==(const fraction &x, int y)
{
    return (x == fraction(y));
}

bool operator!=(const fraction &x, int y)
{
    return (x != fraction(y));
}

bool operator<=(const fraction &x, int y)
{
    return (x <= fraction(y));
}

bool operator>=(const fraction &x, int y)
{
    return (x >= fraction(y));
}

bool operator<(const fraction &x, int y)
{
    return (x < fraction(y));
}

bool operator>(const fraction &x, int y)
{
    return (x > fraction(y));
}

fraction operator+(const fraction &x, int y)
{
    return (x+fraction(y));
}

fraction operator-(const fraction &x, int y)
{
    return (x-fraction(y));
}

fraction operator*(const fraction &x, int y)
{
    return (x * fraction(y));
}

fraction operator/(const fraction &x, int y)
{
return (x/fraction(y));
}

fraction operator^(const fraction &x, int y)
{
    return (x ^ fraction(y));
}

//  Binary Operations int to fraction


bool operator==(int  x, const fraction &y)
{
    return (fraction(x)==y);
}

bool operator!=(int  x, const fraction &y)
{
    return (fraction(x) != y);
}


bool operator<=(int  x, const fraction &y)
{
    return (fraction(x) <= y);
}

bool operator>=(int  x, const fraction &y)
{
    return (fraction(x)>=y);
}

bool operator<(int  x, const fraction &y)
{
    return (fraction(x)<y);
}

bool operator>(int  x, const fraction &y)
{
    return (fraction(x)>y);
}

fraction operator+(int x, const fraction &y)
{
    return (fraction(x)+y);
}

fraction operator-(int x, const fraction &y)
{
    return (fraction(x)-y);
}

fraction operator*(int x, const fraction &y)
{
    return(fraction(x)*y);
}

fraction operator/(int x, const fraction &y)
{
    return (fraction(x)/y);
}

fraction operator^(int x, const fraction &y)
{
    fraction z = fraction(pow(x, (double)(y.num)/y.denom));
    z.reduce();
    return z;
}

// Binary operations fraction to double

bool operator==(const fraction &x, double y)
{
    return (x == fraction(y));
}

bool operator!=(const fraction &x, double y)
{
    return (x != fraction(y));
}

bool operator<=(const fraction &x, double y)
{
    return (x <= fraction(y));
}

bool operator>=(const fraction &x, double y)
{
    return (x >= fraction(y));
}

bool operator<(const fraction &x, double y)
{
    return (x < fraction(y));
}

bool operator>(const fraction &x, double y)
{
    return (x > fraction(y));
}

fraction operator+(const fraction &x, double y)
{
    return (x+fraction(y));
}

fraction operator-(const fraction &x, double y)
{
    return (x-fraction(y));
}

fraction operator*(const fraction &x, double y)
{
    return (x * fraction(y));
}

fraction operator/(const fraction &x, double y)
{
return (x/fraction(y));
}

fraction operator^(const fraction &x, double y)
{
    return (x ^ fraction(y));
}

//  Binary Operations double to fraction


bool operator==(double  x, const fraction &y)
{
    return (fraction(x)==y);
}

bool operator!=(double  x, const fraction &y)
{
    return (fraction(x) != y);
}


bool operator<=(double  x, const fraction &y)
{
    return (fraction(x) <= y);
}

bool operator>=(double  x, const fraction &y)
{
    return (fraction(x)>=y);
}

bool operator<(double  x, const fraction &y)
{
    return (fraction(x)<y);
}

bool operator>(double  x, const fraction &y)
{
    return (fraction(x)>y);
}

fraction operator+(double x, const fraction &y)
{
    return (fraction(x)+y);
}

fraction operator-(double x, const fraction &y)
{
    return (fraction(x)-y);
}

fraction operator*(double x, const fraction &y)
{
    return(fraction(x)*y);
}

fraction operator/(double x, const fraction &y)
{
    return (fraction(x)/y);
}

fraction operator^(double x, const fraction &y)
{
    fraction z = fraction(pow(x, (double)(y.num)/y.denom));
    z.reduce();
    return z;
}

ostream& operator<<(ostream& out, const fraction &frac)
{
    if (frac.decimal)
    {
        double result;
        result = (double)frac.num/frac.denom;
        out << result;
    }
    else
    {
    if (frac.denom!=1)
    out<<frac.num<<"/"<<frac.denom;
    else
        out<<frac.num;
    }
    return out;
}

istream& operator>>(istream& in, fraction &frac)
{
    string line;
    fraction num, denom(1);
    in >> line;
    if (line.find_first_not_of("0123456789/-") != string::npos)
        throw (INVALID_FRACTION);
    size_t pos = line.find('/');
    if (pos != string::npos)
    {
        num = stoi(line.substr(0,pos));
        denom = stoi(line.substr(pos+1));
    }
    else
        num = stoi(line);
    frac = num/denom;
    return in;
}
