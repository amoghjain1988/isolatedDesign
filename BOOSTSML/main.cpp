
#include "AdminTable.h"

//sml::sm<FSM_Admin::AdminStates> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";

FSM_Admin::FSMAdmininstator<> FSM_Admin{};

// External Event Processor
FSM_Admin.ExternalEventProcessor(FSM_Admin::poweredUP{});

return 0;
}


        