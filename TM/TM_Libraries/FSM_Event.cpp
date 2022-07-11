#include "FSM_Event.h"

#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>





        EventBubbler_t::EventBubbler_t(std::shared_ptr<EventCallback>myptr)
        {
                FSM_Event_Bubbler = std::move(myptr);
                std::cout<<"\n EventBubbler_t Constructed";
        }

     

