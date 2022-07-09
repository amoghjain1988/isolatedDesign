

#include "sharedPtr.h"



#include "AdminTable.h"




std::shared_ptr<EventCallback>myptr = std::make_unique<EventCallback>();

FSM_Admin::FSMAdmininstator<> AdminFSM{std::move(myptr)};



class  EventCallback 
{
  
  public:
  EventCallback(){
    std::cout<<"\n EventCallback Contructed!!!";
  }
  
  template<typename myevents>
  void ParseEvent(myevents ev){
    AdminFSM.ExternalEventProcessor(ev);
    
  }


};

int main() {


std::cout<<"\n Program Start - Observing Events \n\n";
    std::cout<<"\n Sh Ptr Use count @ Main Entering: "<<myptr.use_count();

myptr->ParseEvent(FSM_Admin::powerUP{});

    std::cout<<"\n Sh Ptr Use count @ Main Exiting: "<<myptr.use_count();

std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        