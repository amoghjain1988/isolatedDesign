// struct would change based on controller and hW ilst..NO HW Decision Making List will be constant..
//sources will change..





 
    struct GlobalHWData{
    int bms1;
    int bms2;
    int inlinemain;
    // ..

    //.
    //.
    // Sleep Duration etc etc.

    };

GlobalHWData *HWData = new GlobalHWData;


    enum HardwareOutputList
    {

        inlineDetected,
        inlineConfirmed,
        inlineGone,
        StorageWaterMax,
        StorageWatermin,
        motorPullOn,
        motorLiftOn

    };


   HardwareOutputList *HardwareOutput = new HardwareOutputList;

