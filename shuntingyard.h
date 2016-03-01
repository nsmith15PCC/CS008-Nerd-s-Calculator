#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <iostream>
#include "token.h"
#include "stack.h"
#include "queue.h"
#include "mixed.h"

class shuntingyard
{
public:
    shuntingyard();

    static queue<token> makeRPN (queue<token> infixq);

    static mixed calculate (queue<token> rpnq);
};

#endif // SHUNTINGYARD_H
