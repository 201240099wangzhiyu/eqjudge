#include <iostream>
#include <filesystem>
#include <queue>
#include <vector>
#include "prog.hh"
#include "equal.hh"
#include "machine.hh"
using namespace std;
using namespace std::filesystem;
int main(int argc, char *argv[]){
    FILE *abn=fopen("../output/abnormal.csv","w");
    FILE *equ=fopen("../output/equal.csv","w");
    FILE *ine=fopen("../output/inequal.csv","w");
    srand((int)time(0));
    queue<path> type;
    vector<Equality> pairs;
    int base=0;
    for (auto& i : filesystem::directory_iterator(argv[1])) {
        type.push(i.path());
	}
    while(!type.empty()){
        vector<Program> file;
        char req[1200];
        for (auto& i : filesystem::directory_iterator(type.front())){
            path path_1(i.path());
            if((path_1.extension()==".txt")&&(path_1.stem()=="stdin_format")){
                FILE *fp=fopen(path_1.string().c_str(),"r");
                fgets(req,1024,fp);
            }
        }
        Randinput input(req);
        for (auto& i : filesystem::directory_iterator(type.front())){
            path path_1(i.path());
            if(path_1.extension()==".cpp"){
                string name=path_1.string();
                size_t pos = name.find(".cpp");
                string runname = name.substr(0, pos);
                Program prag(path_1.string(),runname,input);
                if(prag.abnormal()){
                    fprintf(abn,"%s\n",prag.srcname().c_str());
                }else{
                    file.push_back(prag);
                }
            }  
        }
        for (int i = 0; i < file.size(); i++ ){
		    for (int j = i+1; j < file.size(); j++ ){
                Equality pair(file[i],file[j]);
                pairs.push_back(pair);    
            }
	    }
        for(int i=0;i<3;i++){
            string* indata=input.getinput();
            for(int j=0;j<file.size();j++){
                file[j].run(indata);
            }
            for(int j=base;j<pairs.size();j++){
                pairs[j].judge();
            }
        }
        type.pop();
        base=pairs.size();
    }
    for(int j=0;j<pairs.size();j++){
        if(pairs[j].isequal()){
            fprintf(equ,"%s,%s\n",pairs[j].getpro1().srcname().c_str(),pairs[j].getpro2().srcname().c_str());
        }else if(!pairs[j].isequal()){
            fprintf(ine,"%s,%s\n",pairs[j].getpro1().srcname().c_str(),pairs[j].getpro2().srcname().c_str());
        }
    }
    fclose(ine);
    fclose(equ);
    fclose(abn);
}