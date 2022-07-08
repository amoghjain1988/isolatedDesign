
#include "AdminTable.h"

#include <queue>

FSM_Admin::FSMAdmininstator<> FSM_Admini {};

int main() {
std::cout<<"\n Program Start - Observe Events \n\n";


// // External Event Processor
// FSM_Admini.ExternalEventProcessor(FSM_Admin::poweredUP{});
// FSM_Admini.ExternalEventProcessor(FSM_Admin::CommsRequired{});

// auto mytemporatyevent = FSM_Admin::provcomple{};
// FSM_Admini.ExternalEventProcessor(mytemporatyevent);

// while(!myEventQueue.empty())
// {

// //std::cout<<"\n value from queu: "<<myEventQueue.front();
//  std::cout<<"\n size of queu: "<<myEventQueue.size();
// //  auto myevent = myEventQueue.front();
// // std::cout<<"\n type name: "<<typeid(myevent).name();

// //  auto mytype = myevent.eventholder;
// // std::cout<<"\n pointer type name: "<<typeid(mytype).name();

// // auto myfinalevnent = mytype.
// // FSM_Admini.ExternalEventProcessor(myevent);
// myEventQueue.pop();


// }

// waterOn

std::cout<<"\n min MAIN: ytypeinfo: "<<typeid(FSM_Admin::evList).name();
std::cout<<"\n";
auto mystruct = FSM_Admin::evList;
mystruct = FSM_Admin::poweredUP{};


FSM_Admini.ExternalEventProcessor(mystruct);

std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        