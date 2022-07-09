#ifndef comms
#define comms
#include <queue>
#include <list>
#include <variant>
 #include "AdminEvents.h"
#include <typeinfo>
#include <string.h>
#include "sharedPtr.h"

std::queue<std::string> evQueue;

class Communications
{ // Sends

public:
         void doWork(std::shared_ptr<EventCallback>meraPointer)
        {
                // using namespace std;
                // const type_info &mytype = typeid(FSM_Admin::powerUP());
                //  std::cout<<"\n typename : "<<mytype.name();
                // meraPointer->ParseEvent(FSM_Admin::powerUP());
                                  std::cout<<"\n Shared Ptr Count inside COmms Class : "<<meraPointer.use_count();

                //   evQueue.push(mytype.name());
                // std::cout<<"\n Rlease event..";
        }
};

#endif
