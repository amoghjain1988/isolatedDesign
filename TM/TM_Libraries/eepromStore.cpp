#include "eepromStore.h"
#include<iostream>
 #include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"

#include <memory.h>


    template <typename t>
    void eeprom_t::Eepromread(std::shared_ptr<t> mainptr){
                //  sptr->ParseEvent(FSM_Admin::Ready{});
               std::shared_ptr<EventCallback>mytemp = std::move(mainptr);
          //    mytemp->ParseEvent(evname);
         // pReturnEvent->ParseEvent(FSM_Admin::RoutineCheck{})
                 std::cout<<"\n Shared Ptr Count inside EEPROM : "<<mytemp.use_count();
                 mytemp->ParseEvent(FSM_Admin::RoutineCheck{});
                //  <<mytemp.use_count();
                                 
                //  <<mybubbler.use_count();

    }