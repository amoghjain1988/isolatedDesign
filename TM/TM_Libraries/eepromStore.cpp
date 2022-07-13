#include "eepromStore.h"
#include<iostream>
 #include "../statemachines/Admin_SML/AdminEvents.h"
#include "../statemachines/Admin_SML/sharedPtr.h"
#include <memory.h>


    template <typename t>
    void eeprom_t::Eepromread(const std::shared_ptr<t> mainptr){
               // std::shared_ptr<EventCallback>mytemp = std::move(mainptr);
                std::cout<<"\n Shared Ptr Count inside EEPROM : "<<mainptr.use_count();           
                mainptr->ParseEvent(FSM_Admin::RoutineCheck{});   // Amogh - Ignore Compiler Warning of Incomplete Type


    }