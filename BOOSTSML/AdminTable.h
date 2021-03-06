#ifndef AdminTable
#define AdminTable

#include "boost_SML.h"
#include <cassert>
#include<iostream>
#include "FSMAdminFunctors.h"


namespace sml = boost::sml;

#define     ENTER     sml::on_entry<_> / 
#define     EXIT      sml::on_exit<_> / 


namespace FSM_Admin{

      template<class = class Dummy>                     // Initializing with non-existing class is required as per the SML.
      class FSMAdmininstator{


            struct AdminTransitionTable {


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

                        /* 
                          --------------------- State Entry Exit Functors Attachment------------------------------------------------------------------------------------------
                        */

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

              template <typename myEvent>
              void ExternalEventProcessor(myEvent evt){
                
                StateTable.process_event(evt);


              };

      private:
              sml::sm<AdminTransitionTable>StateTable{};


      };// FSM Administrator class

};  // namespace FSM





#endif