#include "eepromStore.h"
#include<iostream>
 #include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"

#include <memory.h>


    template <typename t>
    void eeprom_t::Eepromread(t ptrname){
                //  sptr->ParseEvent(FSM_Admin::Ready{});
               std::shared_ptr<EventCallback>mytemp = std::move(ptrname);
          //    mytemp->ParseEvent(evname);
                 std::cout<<"\n Shared Ptr Count inside EEPROM : ";
                //  <<mytemp.use_count();
                                 
                //  <<mybubbler.use_count();

    }