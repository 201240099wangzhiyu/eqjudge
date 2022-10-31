#include <iostream>
#include <filesystem>
#include <queue>
#include "prog.hh"
using namespace std;
using namespace std::filesystem;
int main(int argc, char *argv[]){
    queue<path> type;
    queue<std::string> file;
    for (auto& i : filesystem::directory_iterator(argv[1])) {
        type.push(i.path());
		cout << type.back().string()<< endl;
	}
    for (auto& i : filesystem::directory_iterator(type.front())) {
        file.push(i.path());
		//cout << file.back()<< endl;
        //cout<<i.path().stem()<<endl;
        path path_1(file.back());
        if(path_1.extension()==".txt"){
            FILE *fp=fopen(path_1.string().c_str(),"r");
            char req[1024];
            fgets(req,1024,fp);
            cout<<req<<endl;
            //string cmd="cat "+path_1.string();
            //system(cmd.c_str());
        }
	}
    //system("g++ ../input/4A/48762087.cpp -o ../input/4A/48762087.out");
    //system("../input/4A/48762087.out");
    //system("cat ../input/4A/48762087.cpp");
    /*while(!type.empty()){

    }*/
}