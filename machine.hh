#ifndef MACHINE_HH
#define MACHINE_HH
#include "equal.hh"
class Machine:public Equality{
    private:
    bool _needmachine{true};
    public:
    Machine(Program prog1,Program prog2,bool needmachine):Equality(prog1,prog2),_needmachine(needmachine){}
    void down(){
        _needmachine=false;
    }
    bool getstate(){
        return _needmachine;
    }
};
#endif