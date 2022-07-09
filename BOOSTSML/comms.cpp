#include "comms.h"
#include<iostream>
 #include "AdminEvents.h"
#include "sharedPtr.h"


        template<typename sharedPtrMainClass>
         void Communications::doWork(std::shared_ptr<sharedPtrMainClass>meraPointer)
     
            {
                // using namespace std;
                // const type_info &mytype = typeid(FSM_Admin::powerUP());
                //  std::cout<<"\n typename : "<<mytype.name();
                 meraPointer->ParseEvent(FSM_Admin::TimersUpdated{});
                std::cout<<"\n Shared Ptr Count inside COmms Class : "<<meraPointer.use_count();

                //   evQueue.push(mytype.name());
                // std::cout<<"\n Rlease event..";
        }

