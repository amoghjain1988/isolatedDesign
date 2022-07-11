#ifndef FSM_Event
#define FSM_Event

#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>

template<typename t>
class EventBubbler_t{


public:

        std::shared_ptr<t>FSM_Event_Bubbler;

        EventBubbler_t()
        {
                std::cout<<"\n EventBubbler_t Constructed";
        }

        
      
        void SendEvent(){

        // FSM_Event_Bubbler = std::move(myPointer);
        
        std::cout<<"\n Shared Ptr Count inside Event Bubbler : "<<FSM_Event_Bubbler.use_count();
        
        }

};



#endif