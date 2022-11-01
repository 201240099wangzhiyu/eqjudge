#ifndef EQUALITY_HH
#define EQUALITY_HH

#include "prog.hh"


class Equality{
    private:
    Program _program1;
    Program _program2;
    bool _equal{true};
    public:
    Equality(Program prog1,Program prog2):_program1(prog1),_program2(prog2){}
    bool isequal(){
        return _equal;
    }
    bool judge(){
        std::string file1=_program1.getname()+"output.txt";
        std::string file2=_program2.getname()+"output.txt";
        char ctt1[1200];
        char ctt2[1200];
        FILE* fp1=fopen(file1.c_str(),"r");
        fgets(ctt1,1024,fp1);
        fclose(fp1);
        FILE* fp2=fopen(file2.c_str(),"r");
        fgets(ctt2,1024,fp2);
        fclose(fp2);
        if(strcmp(ctt1,ctt2)!=0){
            _equal=false;
            return false;
        }else{
            return true;
        }
    }
    Program getpro1(){
        return _program1;
    }
    Program getpro2(){
        return _program2;
    }
};


#endif