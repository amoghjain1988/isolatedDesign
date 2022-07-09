

#include "sharedPtr.h"
#include <queue>



#include "AdminTable.h"




std::shared_ptr<EventCallback>myptr = std::make_unique<EventCallback>();

FSM_Admin::FSMAdmininstator<> AdminFSM{std::move(myptr)};



class  EventCallback 
{
  
  public:
  
  template<typename myevents>
  void ParseEvent(myevents ev){
    AdminFSM.ExternalEventProcessor(ev);
    
  }


};

int main() {


std::cout<<"\n Program Start - Observing Events \n\n";
myptr->ParseEvent(FSM_Admin::powerUP{});

    std::cout<<"\n Sh Ptr Use count: "<<myptr.use_count();

std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        