
#include "fsm.h"

sml::sm<FSM_Admin::states> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";


  SM_Admin.process_event(FSM_Admin::poweredUP{});
  


  SM_Admin.process_event(FSM_Admin::CommsRequired{});


return 0;
}


        