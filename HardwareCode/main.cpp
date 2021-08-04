
#include "hardwareRoutines.cpp"

// #include <iostream>
int main()

{
    cout<<"\n Program Start";
    SystemHardware *MainController = new SystemHardware;
    MainController
    ->AddToHWList(new relayPull, locally)
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


    cout<<"\n Finished Adding  HW list\n";

    
     MainController->HardwareRoutine(HWData, locally);



    cout<<"\n Program End \n";

    return 0;
}