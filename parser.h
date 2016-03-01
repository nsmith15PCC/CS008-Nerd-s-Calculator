#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "queue.h"
#include "stack.h"
#include "mixed.h"
#include "token.h"

class parser
{
public:
    parser();
    parser(string line);
    ~parser();

    void feed(string line);
    queue<token>& getQue();
    const queue<token>& getQue() const;
private:
    queue<token> nQue;
    void nukem();

};

#endif // PARSER_H
