#ifndef FSM_Event
#define FSM_Event

#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>


class EventBubbler_t{


public:

        static std::shared_ptr<EventCallback>FSM_Event_Bubbler;

        EventBubbler_t(std::shared_ptr<EventCallback>myptr)
        {
                FSM_Event_Bubbler = std::move(myptr);
                std::cout<<"\n EventBubbler_t Constructed";
        }

     
};

// EventBubbler_t EventBubbler(pReturnEvent);

#endif