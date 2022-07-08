#ifndef comms
#define comms
#include <queue>
#include <list>
#include<variant>

namespace FSM_Admin{
    struct poweredUP ;
    struct AlarmWakeup;
}
class Communications{    // Sends

public:

template<typename t>
void doWork(t myeventlist){

myeventlist = FSM_Admin::poweredUP();


std::cout<<"\n mytypeinfo: "<<typeid(myeventlist).name();

}


};




#endif
