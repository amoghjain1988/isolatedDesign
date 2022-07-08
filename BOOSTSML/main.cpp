
#include "fsm.h"

//sml::sm<FSM_Admin::AdminStates> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";

FSM_Admin::FSMAdmininstator<> SM_Admin{};
SM_Admin.process(FSM_Admin::poweredUP{});

return 0;
}


        