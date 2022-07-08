#ifndef comms
#define comms
#include <queue>
#include <list>
#include<variant>
// #include "FSMAdminFunctors.h"



// template<typename evtName>
// class evtListHolder{

// public:

// auto returnStructType(evtName myev){
//     return myev;
// }

// };


// struct holdClasswithStruct{
// std::type_info* ti;
// void *eventholder;
// holdClasswithStruct(void *myobj){
//     // eventholder = dynamic_cast<myobj*>(myobj);

// }

// };

// std::queue<std::type_info>myEventQueue;


//  std::queue<holdClasswithStruct>myEventQueue;

class Communications{    // Sends

public:

void doWork();


};




#endif
