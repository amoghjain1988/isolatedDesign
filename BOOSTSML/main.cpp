

#include "sharedPtr.cpp"
#include <queue>



#include "AdminTable.h"





static FSM_Admin::FSMAdmininstator<> AdminFSM{std::move(myptr)};



class EventCallback
{
  
  public:

  template<typename evName>
  void ParseEvent(evName ev){
    AdminFSM.ExternalEventProcessor(ev);
    
  }


};

int main() {


std::cout<<"\n Program Start - Observing Events \n\n";
//myptr->ParseEvent(FSM_Admin::powerUP{});

    std::cout<<"\n Sh Ptr Use count: "<<myptr.use_count();

std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        