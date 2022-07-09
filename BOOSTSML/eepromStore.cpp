#include "eepromStore.h"
#include<iostream>
 #include "AdminEvents.h"
#include "sharedPtr.h"




    template<typename t>
    void eeprom_event_bubbler::eventBubbler(std::shared_ptr<t>sptr){

                 sptr->ParseEvent(FSM_Admin::powerUP{});
                std::cout<<"\n Shared Ptr Count inside EEPROM : "<<sptr.use_count();

    }