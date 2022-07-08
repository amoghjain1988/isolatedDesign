

#include <queue>

// #include "AdminFSMObjects.h"

// #include "AdminFSMObjects.cpp"

#include "AdminTable.h"
#include "EventsBridge.h"

class eventOBserver{

FSM_Admin::FSMAdmininstator<> AdminFSM;

public:
            eventOBserver(){

                FSM_Admin::FSMAdmininstator<> AdminFSM{};

            };

            ~eventOBserver(){};
            
            // void ExtractEvent() override{}

            template<typename t>
            void update( t myevname) {
            eventOBserver::AdminFSM.ExternalEventProcessor(myevname);
            }

};









int main() {


std::cout<<"\n Program Start - Observing Events \n\n";
eventOBserver myobs = eventOBserver();

  myobs.update(FSM_Admin::powerUP());

    
std::cout<<"\n\n\n Program End \n\n";

return 0;
}


        