
#include "hardwareRoutines.cpp"

#define FirmwareType 1


// #include <iostream>
int main()

{
    cout<<"\n Program Start";

    #if  ( FirmwareType ==1 )
    SystemHardware *LiftMotorController = new SystemHardware;

    LiftMotorController
    ->AddToHWList(new relayPull, Remotely)
    ->AddToHWList(new relayLift, locally)
    ->AddToHWList(new DepthStorage, Remotely)
    ->AddToHWList(new DepthOverhead, Remotely)
    ->AddToHWList(new LED, locally)
    ->AddToHWList(new UserButton, locally)
    ->AddToHWList(new SDCard, locally)
    ->AddToHWList(new RTC, locally)
    ->AddToHWList(new Valve, Remotely)
    ->AddToHWList(new BMSOverhead, Remotely)
    ->AddToHWList(new BMSStorage, Remotely)
    ->AddToHWList(new InlineMain, Remotely)
    ->AddToHWList(new InlineOverheadPull, Remotely)
    ->AddToHWList(new InlineOverheadLift, Remotely)
    ->AddToHWList(new InlineMain, Remotely);
    
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
    ->AddToHWList(new relayPull, locally)
    ->AddToHWList(new relayLift, Remotely)
    ->AddToHWList(new DepthStorage, Remotely)
    ->AddToHWList(new DepthOverhead, Remotely)
    ->AddToHWList(new LED, locally)
    ->AddToHWList(new UserButton, locally)
    // ->AddToHWList(new SDCard, locally)
    // ->AddToHWList(new RTC, locally)
    // ->AddToHWList(new Valve, Remotely)
    ->AddToHWList(new BMSOverhead, Remotely)
    ->AddToHWList(new BMSStorage, Remotely)
    ->AddToHWList(new InlineMain, Remotely)
    ->AddToHWList(new InlineOverheadPull, Remotely)
    ->AddToHWList(new InlineOverheadLift, Remotely)
    ->AddToHWList(new InlineMain, Remotely);
    

     PullMotorController->HardwareRoutine(HWData, locally);

    delete PullMotorController;
    cout<<"\n Program End \n";
    #endif

    return 0;
}