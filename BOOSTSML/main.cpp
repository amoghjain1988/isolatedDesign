

#include <queue>



#include "AdminTable.h"
#include "EventsBridge.h"

static FSM_Admin::FSMAdmininstator<> AdminFSM{};

template<typename evName>
void ParseEvent(evName ev){
  AdminFSM.ExternalEventProcessor(ev);
}


eventOBserver myobs = eventOBserver();



int main() {


std::cout<<"\n Program Start - Observing Events \n\n";
ParseEvent(FSM_Admin::powerUP{});

    
std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        