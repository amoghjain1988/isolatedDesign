
#include "fsm.h"

sml::sm<states> SM_Admin;



int main() {
std::cout<<"\n Program Start - Observe Events \n\n";


  SM_Admin.process_event(poweredUP{});
  


  SM_Admin.process_event(CommsRequired{});


return 0;
}


        