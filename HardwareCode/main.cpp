
#include "D_HardwareRoutines.cpp"

#define FirmwareType 1


// #include <iostream>
int main()

{
    cout<<"\n Program Start";

    #if  ( FirmwareType ==1 )
    SystemHardware *LiftMotorController = new SystemHardware;

    LiftMotorController
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

   LiftMotorController->HardwareSetup(HWData, locally);

        for(int i = 1; i <3; i++)       // looping through list of HW routines
        {
            cout<<"\n Running Routine Check "<<i<<" ON List";
            LiftMotorController->HardwareRoutine(HWData, locally);
        }

     delete  LiftMotorController;

    cout<<"\n Finished Adding  HW list for Lift Motor Controlelr\n";
    #endif
    

    #if  ( FirmwareType ==2 )

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
    #endif

    return 0;
}