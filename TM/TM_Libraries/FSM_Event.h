#ifndef FSM_Event
#define FSM_Event

#include <memory.h>
#include "../statemachines/Admin_SML/sharedPtr.h"


class EventBubbler_t{


public:
        template <typename t>
        void getPtrLoc(std::shared_ptr<t>);
     
};

// EventBubbler_t EventBubbler(pReturnEvent);

#endif