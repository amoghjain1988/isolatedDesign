#ifndef comms
#define comms
#include <queue>
#include <list>
#include <variant>
 #include "AdminEvents.h"
#include <typeinfo>
#include <string.h>


std::queue<std::string> evQueue;

class Communications
{ // Sends

public:
         void doWork()
        {
                using namespace std;
                const type_info &mytype = typeid(FSM_Admin::powerUP());
                 std::cout<<"\n typename : "<<mytype.name();
                //   evQueue.push(mytype.name());
                // std::cout<<"\n Rlease event..";
        }
};

#endif
