

#include <queue>

// #include "AdminFSMObjects.h"

// #include "AdminFSMObjects.cpp"

#include "AdminTable.h"

FSM_Admin::FSMAdmininstator<> AdminFSM{};





template<typename t>
void update( t myevname) {
 AdminFSM.ExternalEventProcessor(myevname);
}


int main() {


std::cout<<"\n Program Start - Observing Events \n\n";


  update(FSM_Admin::powerUP());


std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        