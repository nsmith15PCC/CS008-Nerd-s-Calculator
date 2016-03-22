#ifndef MEMORY
#define MEMORY

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include "mixed.h"
#include "parser.h"
#include "queue.h"
#include "shuntingyard.h"
#include "token.h"

class memory
{
public:

    memory();
    ~memory();
    memory(const memory &other);

    memory& operator=(const memory &other);

    mixed& setValue(char index);
    const mixed& getValue(char index) const;

    string replaceVars(string input);

    bool store(string input);

    void erase(char index);

    void newMem();

    friend
    ostream& operator<<(ostream& out, const memory &m);

    friend
    istream& operator>>(istream& in, memory &m);

private:
    map<char,mixed> values;
    map<char,mixed>::iterator it;
};



#endif // MEMORY

