#ifndef FSMAdminFunctors
#define FSMAdminFunctors

/*
        SML is based on Miro Diagram at https://miro.com/app/board/uXjVO2or8rs=/
*/


// delete when in esp.
#include<iostream>
#include "../../TM_Libraries/eepromStore.cpp"
#include "sharedPtr.h"
#include "../../TM_Libraries/FSM_Event.h"
#include <memory.h>


// #define bubblePointer  pReturnEvent<EventCallback> // used to provide a pointer which the classes can use to update event

// Communications myespNowObj = Communications(bubblePointer);
EventBubbler_t<EventCallback> EventBubbler = EventBubbler_t<EventCallback>();  // pass template and shared pointer to bubbler class
std::shared_ptr<EventCallback>MainClassPointer;   // used inside State Table


// pReturnEvent<EventCallback>tempevent = std::make_shared<EventCallback>();

eeprom_t eeprom = eeprom_t();
bool eepromset = true;
bool provisionreq = true;




namespace FSM_Admin{

            /* 
                --------------------- State Entry Functions----------------------------------------------------------------------------------------------------- 
            */
            auto FSMInitEntry     = []() { std::cout<<"\n State Entry : FSM Init";   
            // EventBubbler.SendEvent(pReturnEvent<EventCallback>);  
             };// assign ptr to base class
            auto wokeUPEntry      = []() { std::cout<<"\n State Entry : Wokeup";                };
            auto monitoringEntry  = []() { std::cout<<"\n State Entry : Monitoring ";           };
            auto hardwareEntry    = []() { std::cout<<"\n State Entry : Hardware Routine";      };
            auto CommsEntry       = []() { std::cout<<"\n State Entry : Comms Entry";           };
            auto ProvisionEntry   = []() { std::cout<<"\n State Entry : Provision Entry ";      };
            inline auto PoweredUpEntry   = []() { std::cout<<"\n State Entry : PoweredUp Entry ";      };
            auto routineEntry     = []() { std::cout<<"\n State Entry : routine Entry ";          };
              
              
            /* 
              --------------------- State Exit Functions----------------------------------------------------------------------------------------------------- 
            */
            auto FSMInitExit      = []() { std::cout<<"\t State Exiting : FSM Init ";     
                      //  MainClassPointer->ParseEvent<TimersUpdated{}>();
              eeprom.Eepromread(MainClassPointer);
               };
            auto wokeUPExit       = []() { std::cout<<"\t State Exiting : Wokeup ";           };
            auto monitoringExit   = []() { std::cout<<"\t State Exiting : Monitoring";        };
            auto hardwareExit     = []() { std::cout<<"\t State Exiting : Hardware Routine";  };
            auto CommsExit        = []() { std::cout<<"\t State Exiting : Comms Exit ";        };
            auto ProvisionExit    = []() { std::cout<<"\t State Exiting : Provision Exit";     };
            auto PoweredUpExit    = []() { std::cout<<"\t State Exiting : PoweredUp Exit ";    };
            auto routineExit      = []() { std::cout<<"\t State Exiting : routine Exit ";      };


            /* 
              --------------------- Actions run After Gaurd Checks Passes - must NOT return----------------------------------------------------------------------- 
            */
            auto Act_provision    = [](){ std::cout<<"\t Action : Provisioning";              };
            auto Act_setcondac    = [](){ std::cout<<"\t Actton : secondAction";              };
            auto Act_setfinal     = [](){                                                     };
            auto Act_loadEEprom   = [](){std::cout<<"\t Action : Loaded Eeprom";              };
            auto Act_loadRTCData  = [](){std::cout<<"\t Action : Loading RTC Data";           };
            auto Act_sendSleepMsg = [](){std::cout<<"\t Action : Send Sleep Msg";             };
            auto Act_updateTimers = [](){std::cout<<"\t Action : Update Timers";              };
            auto Act_HWActionQueue= [](){std::cout<<"\t Action : Updated HW Action Q";     };

            
            /* 
              --------------------- Gaurd Checks--------------------------------------------------------------------------------------------------- 
            */
            auto G_Provision        = []() { std::cout<<"\t Gaurd: provision Req: "<<provisionreq; return provisionreq;};
            auto G_IsEepromLoaded   = [] () { std::cout<<"\t Gaurd: EEPROM Loaded: "<<eepromset; return eepromset;};
            auto G_CommsRoutine     = [] () { std::cout<<"\t Gaurd: CommsRoutineChecks:"; return true;};

}


#endif

