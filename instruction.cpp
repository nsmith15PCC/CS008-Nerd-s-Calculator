#include "instruction.h"

instruction::instruction()
{

}

instruction::func_ptr instruction::operations[] = {nullptr};

bool instruction::perform(string &line, memory &mem)
{
    ifstream in;
    ofstream out;

    operations['Q'] = &quit;
    operations['E'] = &quit;
    operations['R'] = &load;
    operations['L'] = &load;
    operations['C'] = &clearMem;
    operations['W'] = &write;

    return operations[line[0]] (line, mem, in, out);

}

void instruction::saveFile(string line, memory &mem, ofstream& out)
{
    out.open((line+".txt").c_str());
    out << mem;
    out.close();
}

void instruction::loadFile(string line, memory &mem, ifstream &in)
{
    string filename = line.substr(line.find("<")+1,line.find(">")-line.find("<")-1);
    in.open((filename+".txt").c_str());
    in >> mem;
    in.close();
}

bool instruction::load(string line, memory &mem, ifstream &in, ofstream &out)
{
    string filename = line.substr(line.find("<")+1,line.find(">")-line.find("<")-1);
    loadFile(filename, mem, in);
    return false;
}

bool instruction::quit(string line, memory &mem, ifstream &in, ofstream& out)
{
    return true;
}

bool instruction::write(string line, memory &mem, ifstream &in, ofstream& out)
{
    string filename = line.substr(line.find("<")+1,line.find(">")-line.find("<")-1);
    out.open((filename+".txt").c_str());
    out << mem;
    out.close();
    return line.find("QUIT") < string::npos || line.find("EXIT") < string::npos;

}

bool instruction::clearMem(string line, memory &mem, ifstream &in, ofstream& out)
{

    if(line.find("<") < string::npos && line.find(">") < string::npos)
    {
        char index = line[line.find("<")+1];
        mem.erase(index);
        cout << "Erased memory <" << index << ">\n";
    }
    else
    {
        mem.newMem();
        cout << "Erased all memory!\n";
    }

    return false;

}
