#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <string>

class Program{
    private:
    std::string _name;
    std::string _run_name;
    public:
    Program(std::string name):_name(name){}
    void run(){
        std::string cmd1="g++ "+_name+" -o "+_run_name;
        std::string cmd2=_run_name;
        system(cmd1.c_str());
        system(cmd2.c_str());
    }
    std::string getname(){
        return _name;
    };
};


#endif