
#include "fsm.h"

//sml::sm<FSM_Admin::AdminStates> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";

FSM_Admin::FSMAdmininstator<> SM_Admin{};
SM_Admin.process();
  //SM_Admin.process_event(FSM_Admin::poweredUP{});
  


  //SM_Admin.process_event(FSM_Admin::CommsRequired{});


return 0;
}


        