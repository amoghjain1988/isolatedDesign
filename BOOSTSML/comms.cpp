#include "comms.h"
#include<iostream>
 #include "AdminEvents.h"
#include "sharedPtr.h"


        template<typename t>
        void Communications::doWork(std::shared_ptr<t>meraPointer)
        {
                meraPointer->ParseEvent(FSM_Admin::TimersUpdated{});
                std::cout<<"\n Shared Ptr Count inside COmms Class : "<<meraPointer.use_count();

        }

