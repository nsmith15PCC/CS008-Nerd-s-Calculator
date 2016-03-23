#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "memory.h"

class instruction
{
public:
    instruction();

    typedef bool (*func_ptr) (string, memory &mem, ifstream& in, ofstream &out);

    func_ptr operations[128];

    bool perform(string& line, memory &mem);

    static void saveFile(string line, memory &mem, ofstream &out);

    static void loadFile(string line, memory &mem, ifstream &in);

    static bool load(string, memory &mem, ifstream& in, ofstream& out);

    static bool quit(string, memory &mem, ifstream& in, ofstream& out);

    static bool write(string, memory &mem, ifstream& in, ofstream& out);

    static bool clearMem(string, memory &mem, ifstream& in, ofstream& out);
};

#endif // INSTRUCTION_H
