
#include "fsm.h"

sml::sm<FSM::states> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";


  SM_Admin.process_event(FSM::poweredUP{});
  


  SM_Admin.process_event(FSM::CommsRequired{});


return 0;
}


        