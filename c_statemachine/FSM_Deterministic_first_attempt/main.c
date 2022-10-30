#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


//Different state of ATM machine
typedef enum
{
    NOT_YET_SET,

    STATE_BOOTUP,
    STATE_WATER_ON,
    STATE_WATER_OFF,
    STATE_ROUTINE,
    STATE_SLEEP,
    STATE_ERROR,        // Reboot required
    
    STATE_UNUSED        // Last known State 
} eSystemState;


//Different type events
typedef enum
{
    NO_EVENTS,

    BOOTUP_CHECK_START,
    BOOTUP_CHECK_FINISHED,
    TIME_SOURCE_NOTSET,
    TIME_SOURCE_SET_BLUETOOTH,
    TIME_SOURCE_SET_BESPNOWPEER,
    TIME_SOURCE_SET_BRTCCLOCK,
    TIME_SOURCE_SET_BSAVEDSTATE,
    TIME_REQUEST_TIME_FROM_PEER,

    WAKEUP_SRC_POWERON,         // Bootup Triggers POWER_ON INIT - to Find out WakeUp Source
    WAKEUP_SRC_USERBTN,
    WAKEUP_SRC_INLINE_SENSOR,
    WAKEUP_SRC_TIMER,           // when System wake up source is timer based.


    SYSTEM_STATE_WATER_ON,
    SYSTEM_STATE_WATER_OFF,
    SYSTEM_STATE_ROUTINE,
    SYSTEM_STATE_SLEEP_LIGHT,
    SYSTEM_STATE_SLEEP_DEEP,
    SYSTEM_STATE_LIGHT_SLEEP_INIT,
    SYSTEM_STATE_DEEP_SLEEP_INIT,

    EVENT_COUNT

} eSystemEvent;


//typedef of function pointer
typedef eSystemState (*pfEventHandler)(void);
//structure of state and event with event handler


typedef struct
{
    eSystemState    eCurrState;
    eSystemEvent    eStateMachineEvent;
    pfEventHandler  pfStateMachineEventHandler;
    eSystemState    eNextState;
} sStateMachine;



// handle Bootup Function at Power up
eSystemState PowerOnReset(void)
{

    printf("\n entered system state BOOTUP_CHECK_START : [%d]", BOOTUP_CHECK_START);
    printf("\n Handle all power on reset settings");
    return STATE_ROUTINE;
}



// handle Power Settings when water is on
eSystemState PowerOnWaterOn(void)
{
    printf("\n entered system state [%d]", SYSTEM_STATE_WATER_ON);
    return STATE_ROUTINE;
}

// handle Bootup Function at Power up
eSystemState DeepSleepWakeup(void)
{

    printf("\n entered system state [%d]", BOOTUP_CHECK_START);
    printf("\n Handle all power on reset settings");
    return STATE_ROUTINE;
}

/// @brief  State Machine that Handles Events in Certain States
///         Performs a function and
///         can New State be added here as well?
sStateMachine asStateMachine [] =
{
    // CURR_STATE   // EVENT                    // FUNCTION         // NEXT STATE
    {STATE_BOOTUP,  BOOTUP_CHECK_START,         PowerOnReset,       STATE_ROUTINE   },
    {STATE_BOOTUP,  SYSTEM_STATE_WATER_ON,      PowerOnWaterOn,     STATE_ROUTINE   },
    {STATE_BOOTUP,  SYSTEM_STATE_SLEEP_DEEP,    DeepSleepWakeup,    STATE_ROUTINE   },

};


int printRandoms(int lower, int upper)
{
   
    int num = (rand() % (upper - lower + 1)) + lower;
    printf(" event : [%d] ", num);
    
    return num;
}

//main function
int main(int argc, char *argv[])
{
    int lower = NO_EVENTS, upper = EVENT_COUNT;
    srand(time(0));
    printf("\n Running FSM \n ");

    eSystemState eNextState = STATE_BOOTUP;

    while(1)
    {
        
        eSystemEvent eNewEvent = SYSTEM_STATE_WATER_ON;
        printRandoms(lower, upper);

        if  ( 
                (eNextState <= STATE_UNUSED) && 
                (eNewEvent < EVENT_COUNT)&& 
                (asStateMachine[eNextState].eStateMachineEvent == eNewEvent) &&         // if event is mapped to a state
                (asStateMachine[eNextState].pfStateMachineEventHandler != NULL)         // if function check is NOT NULL
            )
        {   
            // Next state should be picked up From the array and NOT the return type of the array based function pointer
            (*asStateMachine[eNextState].pfStateMachineEventHandler)();    // Run the Function Check
            eNextState = 

            printf("\n New State : [%d] \n ", eNextState);

        }
        else
        {
            printf("\n\t\t State not handled..");
        }
        
        sleep(1);                        

        eNewEvent = printRandoms(lower, upper);
    }
    return 0;
}