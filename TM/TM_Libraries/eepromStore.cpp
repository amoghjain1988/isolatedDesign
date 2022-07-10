#include "eepromStore.h"
#include<iostream>
 #include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"




    template<typename t>
    void eeprom_event_bubbler::eventBubbler(std::shared_ptr<t>sptr){

                 sptr->ParseEvent(FSM_Admin::Ready{});
                std::cout<<"\n Shared Ptr Count inside EEPROM : "<<sptr.use_count();

    }