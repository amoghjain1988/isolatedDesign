#include "boost_SML.hpp"
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


class Admin_FSM{

public:

        /* 
                  --------------------- Events -----------------------------------------------------------------------------------------------------
            */
            enum AdminEvents{
              e_poweredUP,
              e_SleepTime,
              e_waterOn,
              e_provcomple,
              e_AlarmWakeup,
              e_HwValUpdated,
              e_updateTimers,
              e_CommsRequired
            };


};


class Admin_FSM_Controller: public Admin_FSM{


public:

void UpdateState(){
  
}

};
            
    


            
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


struct states {


          auto operator()() const noexcept {

            using namespace sml;
            /* 
              --------------------- System States--------------------------------------------------------------------------------------------- 
              */
            
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

            *poweredUp        + event<poweredUP> [G_IsEepromLoaded]                                         =       routine
            ,poweredUp        + event<poweredUP> [!G_IsEepromLoaded] / (Act_provision)                      =       Provision
            ,poweredUp        + event<AlarmWakeup>                                                          =       hardware                                 
            ,hardware         + event<HwValUpdated>                                                         =       routine 
            ,Communication    + event<SleepTime> [G_Provision]/(Act_setfinal)                               =       Provision
            ,Provision        + event<provcomple>                                                           =       Communication
            ,routine          + event<RoutineCheck>                                                         =       Monitoring
            ,Monitoring       + event<TimersUpdated>                                                        =       routine
            ,routine          + event<CommsRequired>                                                        =       Communication
            ,routine          + event<waterOn>/(Act_updateTimers)                                           =       Monitoring
            ,Monitoring       + event<TimersUpdated>                                                        =       routine
            ,Monitoring       + event<HWActionReq>  /(Act_HWActionQueue)                                     =       hardware


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


sml::sm<states> SM_Admin;

void EventConverter(int);


int main() {
// /std::cout<<"\n Program Start - Observe Events \n\n";


  SM_Admin.process_event(poweredUP{});
//  SM_Admin.process_event(waterOn{});

  {
  //  std::cout<<"\t Delay Start";

    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 1s);
 //   std::cout<<"\t   Delay End";

    
  }
  


  SM_Admin.process_event(CommsRequired{});



  // assert(SM_Admin.is(sml::X));
while(1)
{
  //std::cout<<"\n Enter an Event End \n\n";

  int x;
  std::cin>>x;
  
  if(x == -1)
  break;
  
  EventConverter(x);
  //std::cout<<"value entered: "<<x<<"\n";

}


}


            void EventConverter(int myevent)
            {

                switch(myevent)
                {
                  case e_poweredUP:     SM_Admin.process_event(poweredUP{});  break;
                  case e_SleepTime:     SM_Admin.process_event(SleepTime{});  break;
                  case e_waterOn:       SM_Admin.process_event(waterOn{});  break;                  
                  case e_provcomple:    SM_Admin.process_event(provcomple{});  break;
                  case e_AlarmWakeup:   SM_Admin.process_event(AlarmWakeup{});  break;
                  case e_HwValUpdated:  SM_Admin.process_event(HwValUpdated{});  break;
                  case e_updateTimers:  SM_Admin.process_event(updateTimers{});  break;
                  case e_CommsRequired: SM_Admin.process_event(CommsRequired{});  break;
                  default:              std::cout<<"\n \t\t Error!";          break;


                }

                

            }