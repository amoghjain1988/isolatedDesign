#ifndef FSM_Event
#define FSM_Event

#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>

template<typename t>
class EventBubbler_t{

        std::shared_ptr<t>FSM_Event_Bubbler;

public:


        
        template<typename e>
        void SendEvent(){
        
        std::cout<<"\n Shared Ptr Count inside Event Bubbler : "<<FSM_Event_Bubbler.use_count();
        
        }
        // void doWork()
        // {
        //         FSM_Event_Bubbler->ParseEvent(FSM_Admin::TimersUpdated{});
        //         std::cout<<"\n Shared Ptr Count inside Event Bubbler : "<<FSM_Event_Bubbler.use_count();
        // }
        
};


template<typename t>
class FSM_Event_Return_t{

public:

void PassEvent(t myevent){
        

}

};

#endif