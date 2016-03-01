#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum FRACTION_ERRORS {DIVIDEBYZERO, INVALID_FRACTION};

class fraction
{
    public:
        fraction(int n = 0, int d = 1);
        ~fraction();
        fraction(const double &other);
        fraction(const fraction &other);
        fraction& operator=(const fraction &other);
        fraction& operator=(const int &other);
        fraction& operator=(const double &other);

        const int& numerator() const;
        const int& denominator() const;
        const bool& setdecimal() const;


        void setValue(int n = 0, int d = 1);

        fraction& operator+=(const fraction &other);
        fraction& operator-=(const fraction &other);
        fraction& operator*=(const fraction &other);
        fraction& operator/=(const fraction &other);
        fraction& operator^=(const fraction &other);
        fraction& operator+=(int other);
        fraction& operator-=(int other);
        fraction& operator*=(int other);
        fraction& operator/=(int other);
        fraction& operator^=(int other);
        fraction& operator+=(double other);
        fraction& operator-=(double other);
        fraction& operator*=(double other);
        fraction& operator/=(double other);
        fraction& operator^=(double other);

        // Binary operations fraction to fraction
        friend
        fraction operator+(const fraction &x, const fraction &y);
        friend
        fraction operator-(const fraction &x, const fraction &y);
        friend
        fraction operator*(const fraction &x, const fraction &y);
        friend
        fraction operator/(const fraction &x, const fraction &y);
        friend
        fraction operator^(const fraction &x, const fraction &y);

        friend
        bool operator==(const fraction &x, const fraction &y);

        friend
        bool operator!=(const fraction &x, const fraction &y);

        friend
        bool operator<=(const fraction &x, const fraction &y);

        friend
        bool operator>=(const fraction &x, const fraction &y);

        friend
        bool operator<(const fraction &x, const fraction &y);

        friend
        bool operator>(const fraction &x, const fraction &y);

        // Binary operations fraction to int

        friend
        bool operator==(const fraction &x, int y);

        friend
        bool operator!=(const fraction &x, int y);

        friend
        bool operator<=(const fraction &x, int y);

        friend
        bool operator>=(const fraction &x, int y);

        friend
        bool operator<(const fraction &x, int y);

        friend
        bool operator>(const fraction &x, int y);

        friend
        fraction operator+(const fraction &x, int y);

        friend
        fraction operator-(const fraction &x, int y);

        friend
        fraction operator*(const fraction &x, int y);

        friend
        fraction operator/(const fraction &x, int y);

        friend
        fraction operator^(const fraction &x, int y);

        //  Binary Operations int to fraction

        friend
        bool operator==(int  x, const fraction &y);

        friend
        bool operator!=(int  x, const fraction &y);

        friend
        bool operator<=(int  x, const fraction &y);

        friend
        bool operator>=(int  x, const fraction &y);

        friend
        bool operator<(int  x, const fraction &y);

        friend
        bool operator>(int  x, const fraction &y);
        
        friend
        fraction operator+(int x, const fraction &y);

        friend
        fraction operator-(int x, const fraction &y);

        friend
        fraction operator*(int x, const fraction &y);

        friend
        fraction operator/(int x, const fraction &y);

        friend
        fraction operator^(int x, const fraction &y);

        //  Binary Operations double to fraction

        friend
        bool operator==(double  x, const fraction &y);

        friend
        bool operator!=(double  x, const fraction &y);

        friend
        bool operator<=(double  x, const fraction &y);

        friend
        bool operator>=(double  x, const fraction &y);

        friend
        bool operator<(double  x, const fraction &y);

        friend
        bool operator>(double  x, const fraction &y);
       
        friend
        fraction operator+(double x, const fraction &y);

        friend
        fraction operator-(double x, const fraction &y);

        friend
        fraction operator*(double x, const fraction &y);

        friend
        fraction operator/(double x, const fraction &y);

        friend
        fraction operator^(double x, const fraction &y);
        
        // Binary operations fraction to double

        friend
        bool operator==(const fraction &x, double y);

        friend
        bool operator!=(const fraction &x, double y);

        friend
        bool operator<=(const fraction &x, double y);

        friend
        bool operator>=(const fraction &x, double y);

        friend
        bool operator<(const fraction &x, double y);

        friend
        bool operator>(const fraction &x, double y);

        friend
        fraction operator+(const fraction &x, double y);

        friend
        fraction operator-(const fraction &x, double y);

        friend
        fraction operator*(const fraction &x, double y);

        friend
        fraction operator/(const fraction &x, double y);

        friend
        fraction operator^(const fraction &x, double y);


        friend
        ostream& operator<<(ostream& out, const fraction &frac);

        friend
        istream& operator>>(istream& in, fraction &frac);

    protected:
        void reduce();
        int& numerator();
        int& denominator();
        bool& setdecimal();

    private:
        int num, denom;
        bool decimal;

        void copy(const fraction& other);
        int gcd(int p, int q);
};

#endif // FRACTION_H
