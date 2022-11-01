#ifndef MACHINE_HH
#define MACHINE_HH
class Machine{
    private:
    bool _needmachine{true};
    public:
    Machine(bool needmachine):_needmachine(needmachine){}
    void down(){
        _needmachine=false;
    }
    bool getstate(){
        return _needmachine;
    }
};
#endif