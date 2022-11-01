#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <string>
#include "randinput.hh"
class Program{
    private:
    std::string _name;
    std::string _run_name;
    Randinput _input;
    public:
    Program(std::string name,std::string runname,Randinput input):_name(name),_run_name(runname),_input(input){}
    void run(std::string arg[1024]){
        int num=_input.getnum();
        std::string cmd1="g++ "+_name+" -w -o "+_run_name+".out";
        std::string cmd2=_run_name+".out"+" < "+_run_name+"input.txt"+" > "+_run_name+"output.txt"+" 2>&1";
        std::string input="";
        for(int i=0;i<num;i++){
            input+=arg[i];
            input+=" ";
        }
        std::string filename=_run_name+"input.txt";
        FILE *fp=fopen(filename.c_str(),"w+");
        fprintf(fp,"%s\n",input.c_str());
        fclose(fp);
        //std::cout<<input<<filename<<std::endl;
        //std::cout<<cmd2<<std::endl;
        system(cmd1.c_str());
        system(cmd2.c_str());
        //std::cout<<std::endl<<"ans"<<std::endl;
        
    }
    bool abnormal(){
        int num=0;
        FILE* fp=fopen(_name.c_str(),"r");
        char ctt[1200];
        std::string id1=">>";
        std::string id2="&";
        while(!feof(fp)){
            fgets(ctt,1024,fp);
            std::string origin(ctt);
            for(int i = 0 ; (i = origin.find(id1,i)) != std::string::npos ;i++ , num ++ );
            for(int i = 0 ; (i = origin.find(id2,i)) != std::string::npos ;i++ , num ++ );
        }
        fclose(fp);
        if(num!=_input.getnum()){
            return true;
        }
        return false;
    }
    std::string getname(){
        return _run_name;
    }
    std::string srcname(){
        return _name;
    }
    Randinput getinput(){
        return _input;
    }
};


#endif