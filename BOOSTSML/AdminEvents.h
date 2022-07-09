#ifndef AdminEvents
#define AdminEvents

#include <iostream>
#include <variant>

namespace FSM_Admin{
   /* 
            --------------------- Events -----------------------------------------------------------------------------------------------------
            */
       
            struct powerUP    { powerUP()     { std::cout<<" \t Event : Power Up event ";}    };
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

            
          //  std::variant<powerUP, SleepTime,AlarmWakeup>evList;
}

namespace evEnums{

        enum class myEvents{

                powerUP,
                SleepTime,
                waterOn,
                provcomple,
                AlarmWakeup,
                HwValUpdated,
                updateTimers
        };


}


#endif