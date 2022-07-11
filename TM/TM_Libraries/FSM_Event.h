#ifndef FSM_Event
#define FSM_Event

#include<iostream>
#include <memory.h>


class EventBubbler_t{


public:

        std::shared_ptr<EventCallback>FSM_Event_Bubbler;

        EventBubbler_t(std::shared_ptr<EventCallback>myptr);
     
};

// EventBubbler_t EventBubbler(pReturnEvent);

#endif