#ifndef FSMAdminFunctors
#define FSMAdminFunctors

/*
        SML is based on Miro Diagram at https://miro.com/app/board/uXjVO2or8rs=/
*/


// delete when in esp.
#include<iostream>
#include "comms.h"
#include<variant>

Communications myespNowObj = Communications();




bool eepromset = true;
bool provisionreq = true;


namespace FSM_Admin{
   /* 
            --------------------- Events -----------------------------------------------------------------------------------------------------
            */
       
            struct poweredUP    { poweredUP()     { std::cout<<" \t Event : Power Up event ";}    };
            struct SleepTime    { SleepTime()     { std::cout<<" \t Event : SleepTime event ";}   };
            struct waterOn      { waterOn()       { std::cout<<" \t Event : WaterOn event ";}     };
            struct provcomple   { provcomple()    { std::cout<<" \t Event : provcomple event ";}  };
            struct AlarmWakeup  { AlarmWakeup()   { std::cout<<" \t Event : AlarmWakeup ";}       };
            struct HwValUpdated { HwValUpdated()  { std::cout<<" \t Event : HwValUpdated ";}      };
            struct updateTimers { updateTimers()  { std::cout<<" \t Event : updateTimers ";}      };
            struct CommsRequired{ CommsRequired() { std::cout<<" \t Event : CommsRequired ";}     };
            struct TimersUpdated{ TimersUpdated() { std::cout<<" \t Event : TimersUpdated ";}     };
            struct RoutineCheck { RoutineCheck()  { std::cout<<" \t Event : RoutineCheck ";}      };
            struct HWActionReq  { HWActionReq()   { std::cout<<" \t Event : HWActionReq ";}       };

            /* 
                --------------------- State Entry Functions----------------------------------------------------------------------------------------------------- 
            */
            auto FSMInitEntry      = []() { std::cout<<"\n State Entry : FSM Init";            };
            auto wokeUPEntry      = []() { std::cout<<"\n State Entry : Wokeup";              };
            auto monitoringEntry  = []() { std::cout<<"\n State Entry : Monitoring ";         };
            auto hardwareEntry    = []() { std::cout<<"\n State Entry : Hardware Routine";    };
            auto CommsEntry       = []() { std::cout<<"\n State Entry : Comms Entry";     myespNowObj.doWork();     };
            auto ProvisionEntry   = []() { std::cout<<"\n State Entry : Provision Entry ";     };
            auto PoweredUpEntry   = []() { std::cout<<"\n State Entry : PoweredUp Entry ";     };
            auto routineEntry     = []() { std::cout<<"\n State Entry : routine Entry ";       };
              
              
            /* 
              --------------------- State Exit Functions----------------------------------------------------------------------------------------------------- 
            */
            auto FSMInitExit      = []() { std::cout<<"\t State Exiting : FSM Init ";           };
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
            auto Act_HWActionQueue = [](){std::cout<<"\t Action : Updated HW Action Q";     };

            
            /* 
              --------------------- Gaurd Checks--------------------------------------------------------------------------------------------------- 
            */
            auto G_Provision        = []() { std::cout<<"\t Gaurd: provision Req: "<<provisionreq; return provisionreq;};
            auto G_IsEepromLoaded   = [] () { std::cout<<"\t Gaurd: EEPROM Loaded: "<<eepromset; return eepromset;};
            auto G_CommsRoutine     = [] () { std::cout<<"\t Gaurd: CommsRoutineChecks:"; return true;};

}


#endif

