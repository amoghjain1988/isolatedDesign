#ifndef fsm
#define fsm

#include "boost_SML.h"
#include <cassert>
#include<iostream>

#include <cassert>
#include <iostream>

// C++ clocks only remove for esp
#include <chrono>
#include <thread>

namespace sml = boost::sml;
struct states;

#define     ENTER     sml::on_entry<_> / 
#define     EXIT      sml::on_exit<_> / 


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
            auto CommsEntry       = []() { std::cout<<"\n State Entry : Comms Entry";          };
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


template<class = class Dummy>
class FSMAdmininstator{


struct AdminStates {


          auto operator()() const noexcept {

            using namespace sml;
            /* 
              --------------------- System States--------------------------------------------------------------------------------------------- 
              */
            
            const auto FSMInit         = state<class FSMInit>;
            const auto poweredUp        = state<class poweredUp>;
            const auto routine          = state<class routine>;   // timer resets
            const auto Wokeup           = state<class Wokeup>;
            const auto Provision        = state<class Provision>;
            const auto UserEvent        = state<class UserEvent>;
            const auto Communication    = state<class Communication>;
            const auto hardware         = state<class hardware>;
            const auto Monitoring       = state<class Monitoring>;
            const auto NapTime          = state<class NapTime>;
            const auto WaterOn          = state<class WaterOn>;
            const auto MotorOn          = state<class MotorOn>;


            /* 
              --------------------- Transition Tables Checks------------------------------------------------------------------------------------------
            */

            return make_transition_table(
            FSMInit(H)            + event<poweredUP>                                                            =       poweredUp
            , poweredUp        + event<poweredUP> [G_IsEepromLoaded]                                         =       routine
            , poweredUp        + event<poweredUP> [!G_IsEepromLoaded] / (Act_provision)                      =       Provision
            , poweredUp        + event<AlarmWakeup>                                                          =       hardware                                 
            , hardware         + event<HwValUpdated>                                                         =       routine 
            , Communication    + event<SleepTime> [G_Provision]/(Act_setfinal)                               =       Provision
            , Provision        + event<provcomple>                                                           =       Communication
            , routine          + event<RoutineCheck>                                                         =       Monitoring
            , Monitoring       + event<TimersUpdated>                                                        =       routine
            , routine          + event<CommsRequired>                                                        =       Communication
            , routine          + event<waterOn>/(Act_updateTimers)                                           =       Monitoring
            , Monitoring       + event<HWActionReq>  /(Act_HWActionQueue)                                     =       X


            , FSMInit       +   ENTER   FSMInitEntry
            , FSMInit       +   EXIT    FSMInitExit 
            , poweredUp       +   ENTER   PoweredUpEntry
            , poweredUp       +   EXIT    PoweredUpExit   
            , routine         +   ENTER   routineEntry
            , routine         +   EXIT    routineExit                            
            , hardware        +   ENTER   hardwareEntry
            , hardware        +   EXIT    hardwareExit
            , Monitoring      +   ENTER   monitoringEntry
            , Monitoring      +   EXIT    monitoringExit              
            , Wokeup          +   ENTER   wokeUPEntry
            , Wokeup          +   EXIT    wokeUPExit
            , Communication   +   ENTER   CommsEntry
            , Communication   +   EXIT    CommsExit
            , Provision       +   ENTER   [] { std::cout << "\nProvision on entry" ; }
            , Provision       +   EXIT    []   { std::cout << "\nProvision on exit"; }

            );            
          }   // operator () 

  };      // struct states

public:

void process(){
  
  SM_Admin.process_event(FSM_Admin::poweredUP{});


};

private:
sml::sm<AdminStates>SM_Admin{};


};
// FSM Administrator class

};  // namespace FSM





#endif