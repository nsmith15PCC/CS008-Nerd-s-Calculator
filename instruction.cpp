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
    string filename = line.substr(line.find("<")+1,line.find(">")-line.find("<")-1);
    out.open((filename+".txt").c_str());
    out << mem;
    out.close();
}

void instruction::loadFile(string line, memory &mem, ifstream &in)
{
    string filename = line.substr(line.find("<")+1,line.find(">")-line.find("<")-1);
    in.open((filename+".txt").c_str());
    if(in.fail())
        cout << "No such file exists\n";
    else
    {
        in >> mem;
        in.close();
    }
}

bool instruction::load(string line, memory &mem, ifstream &in, ofstream &out)
{
    loadFile(line, mem, in);
    return false;
}

bool instruction::quit(string line, memory &mem, ifstream &in, ofstream &out)
{
    string ans;

    if(line.find("<") < string::npos && line.find(">") < string::npos)
        saveFile(line, mem, out);
    else
    {
        cout << "Would you like to save the data in your memory? : ";
        getline(cin,ans);
        if(toupper(ans[0]) == 'Y')
        {
            cout << "Type the file name : ";
            getline(in,ans);
            saveFile(ans, mem, out);
        }
    }
    return true;
}

bool instruction::write(string line, memory &mem, ifstream &in, ofstream& out)
{  
    saveFile(line, mem, out);
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
