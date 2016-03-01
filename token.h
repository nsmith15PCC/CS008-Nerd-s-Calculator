#ifndef TOKEN
#define TOKEN
#include "mixed.h"

class token
{
public:

    typedef token (*func_ptr) (const token&, const token&);

    token(char o = NULL);
    token(const mixed &v);
    token(const double &other);
    token(const int &other);
    token(const fraction &other);
    token(const token &other);

    token& operator=(const char &other);
    token& operator=(const fraction &other);
    token& operator=(const double &other);
    token& operator=(const int &other);
    token& operator=(const mixed &other);
    token& operator=(const token &other);

    const bool& isOperator() const;
    bool& isOperator();

    mixed& value ();
    const mixed& value () const;

    char& op();
    const char& op() const;

    unsigned short int priority() const;

    token perform(const token &x, const token &y);



    friend
    bool operator<(const token x, const token y);

    friend
    bool operator>(const token x, const token y);

    friend
    bool operator<=(const token x, const token y);

    friend
    bool operator>=(const token x, const token y);

    friend
    bool operator==(const token x, const token y);

    friend
    bool operator!=(const token x, const token y);

    friend
    std::ostream& operator<<(std::ostream& out, const token &t);

    friend
    std::istream& operator>>(std::ostream& in, const token &t);



private:
    char theOp;
    mixed thevalue;
    bool Operator;

    static func_ptr allOps[128];
    static int allPriorities[128];

    static token add (const token &x, const token &y);
    static token subtract (const token &x, const token &y);
    static token times (const token &x, const token &y);
    static token divide (const token &x, const token &y);
    static token power (const token &x, const token &y);
};

#endif // TOKEN

