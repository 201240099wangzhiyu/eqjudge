#ifndef RANDINPUT_HH
#define RANDINPUT_HH
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
enum ty{
    INT,STR,CHAR
};
typedef struct trireq{
    ty type;
    int start;
    int end;
}trireq;

class Randinput{
    private:
    int _num{0};
    char seed[52] = {
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z','a','b','c','d',
    'e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x',
    'y','z'
    };
    std::vector<trireq> _request;
    public:
    Randinput(char *request){
        char* p = strtok(request, " ");
        while(p) {
            std::string s(p);
            trireq node;
            if((s.substr(0,3).compare("int")==0)||(s.substr(0,6).compare("string")==0)){
                if(s.substr(0,3).compare("int")==0){
                    node.type=INT;
                }else{
                    node.type=STR;
                }
                bool started1=false;
                bool started2=false;
                std::string start="";
                std::string end="";
                for (int i = 0; i < s.length(); i++){
                    if(s[i] == ','){
                        node.start=atoi(start.c_str());
                    }
                    if(s[i] == ')'){
                        node.end=atoi(end.c_str());
                    }
                    if(started1){
                        start+=s[i];
                    }
                    if(started2){
                        end+=s[i];
                    }
                    if (s[i] == '('){
                        started1=true;
		            }
                    if (s[i] == ','){
                        started2=true;
		            }
	            }
            }else if(s.substr(0,4).compare("char")==0){
                node.type=CHAR;
                node.start=0;
                node.end=0;    
            }
	        _request.push_back(node);
	        p = strtok(NULL, " ");
            _num++;
        }
    }
    int getnum(){
        return _num;
    }
    int randnum(int a,int b){
        int ans=rand()%b;
        while(ans<a){
            ans=rand()%b;
        }
        return ans;
    }
    const char randchar(){
        int select=rand()%52;
        return seed[select];
    }
    const char *randstr(int a,int b){
        static std::string ans="";
        int len=randnum(a,b);
        for(int i=0;i<len;i++){
            ans+=randchar();
        }
        return ans.c_str();
    }
    std::vector<trireq> getrequest(){
        return _request;
    }
    std::string *getinput(){
        static std::string arg[1024];
        for(int i=0;i<_num;i++){
            if(_request[i].type==INT){
                arg[i]=std::to_string(randnum(_request[i].start,_request[i].end));
            }else if(_request[i].type==STR){
                arg[i]=randstr(_request[i].start,_request[i].end);
            }else if(_request[i].type==CHAR){
                arg[i]=randchar();
            }
        }
        return arg;
    }
};
#endif