#ifndef COMMS
#define COMMS

#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"

class Communications{
public:

        template<typename t>
        void doWork(std::shared_ptr<t>meraPointer)
        {
                meraPointer->ParseEvent(FSM_Admin::TimersUpdated{});
                std::cout<<"\n Shared Ptr Count inside COmms Class : "<<meraPointer.use_count();

        }

        
};

#endif