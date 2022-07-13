#include "FSM_Event.h"
#include<iostream>
#include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>




    template <typename t>
        void EventBubbler_t::getPtrLoc(std::shared_ptr<t>myptr)
        {    
           //     std::shared_ptr<EventCallback>FSM_Event_Bubbler = std::move(myptr);
                std::cout<<"\n myptr Constructed";
                myptr->ParseEvent(FSM_Admin::CommsRequired{});
                                std::cout<<"\n EventBubbler_t Ptr Count:"<<myptr.use_count();
    
        }

     

