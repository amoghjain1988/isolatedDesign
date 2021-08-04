#ifndef Z_ControllerManager
#define Z_ControllerManager
#include "B_Hardware_COR_Base.cpp"
#include "C_HardwareSetup.cpp"
#include "D_HardwareRoutines.cpp"

#define ControllerType 1

 

    #if  ( ControllerType ==2 )
void comingsoon()
{
    cout<<"\n Program Start";
    SystemHardware *PullMotorController = new SystemHardware;
    PullMotorController
    ->AddToHWRoutineList(new relayPull, locally)
    ->AddToHWRoutineList(new relayLift, Remotely)
    ->AddToHWRoutineList(new DepthStorage, Remotely)
    ->AddToHWRoutineList(new DepthOverhead, Remotely)
    ->AddToHWRoutineList(new LED, locally)
    ->AddToHWRoutineList(new UserButton, locally)
    // ->AddToHWRoutineList(new SDCard, locally)
    // ->AddToHWRoutineList(new RTC, locally)
    // ->AddToHWRoutineList(new Valve, Remotely)
    ->AddToHWRoutineList(new BMSOverhead, Remotely)
    ->AddToHWRoutineList(new BMSStorage, Remotely)
    ->AddToHWRoutineList(new InlineMain, Remotely)
    ->AddToHWRoutineList(new InlineOverheadPull, Remotely)
    ->AddToHWRoutineList(new InlineOverheadLift, Remotely)
    ->AddToHWRoutineList(new InlineMain, Remotely);
    

     PullMotorController->HardwareRoutine(HWData, locally);

    delete PullMotorController;
    cout<<"\n Program End \n";
 }
  #endif



#if  ( ControllerType ==1 )
class ControllerManager_t
{
    public:
    SystemHardwareSetup *LiftMotorSetup = new SystemHardwareSetup;
    SystemHWRoutine *LiftMotorRoutine = new SystemHWRoutine;

    void HardwareSetup()
    {

        LiftMotorSetup
        ->AddToHWSetupList(new PowerSetup)
        ->AddToHWSetupList(new relayLiftSetup)
        ->AddToHWSetupList(new LEDSetup)
        ->AddToHWSetupList(new SDCardSetup)
        ->AddToHWSetupList(new BtnSetup)
        ->AddToHWSetupList(new relayPullSetup)
        ->AddToHWSetupList(new relayPullSetup);
    }

    void HardwareSetupCycler()
    {
        LiftMotorSetup->HardwareSetup(HWSetupVars); // different for each contolelr?        
    }

    void DeleteHWSetupObject()
    {
        delete     LiftMotorSetup;
    }


    void HardwareRoutineListSetup()
    {
        LiftMotorRoutine
        ->AddToHWRoutineList(new PowerSettings, locally)
        ->AddToHWRoutineList(new relayPull, Remotely)
        ->AddToHWRoutineList(new relayLift, locally)
        ->AddToHWRoutineList(new DepthStorage, Remotely)
        ->AddToHWRoutineList(new DepthOverhead, Remotely)
        ->AddToHWRoutineList(new LED, locally)
        ->AddToHWRoutineList(new UserButton, locally)
        ->AddToHWRoutineList(new SDCard, locally)
        ->AddToHWRoutineList(new RTC, locally)
        ->AddToHWRoutineList(new Valve, Remotely)
        ->AddToHWRoutineList(new BMSOverhead, Remotely)
        ->AddToHWRoutineList(new BMSStorage, Remotely)
        ->AddToHWRoutineList(new InlineMain, Remotely)
        ->AddToHWRoutineList(new InlineOverheadPull, Remotely)
        ->AddToHWRoutineList(new InlineOverheadLift, Remotely)
        ->AddToHWRoutineList(new InlineMain, Remotely);


    }

    void HardwareRoutineListCycler()
    {
    for(int i = 1; i <3; i++)       // looping through list of HW routines
    {
        cout<<"\n Running Routine Check "<<i<<" ON List";
        LiftMotorRoutine->HardwareRoutine(HWData, locally);
    }        

    }
    void DeleteHWRoutineObject()
    {
        delete     LiftMotorRoutine;

    }




};

    #endif

    #endif


