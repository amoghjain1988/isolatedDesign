// struct would change based on controller and hW ilst..NO HW Decision Making List will be constant..
//sources will change..


    #ifndef A_HardwareData
    #define A_HardwareData


    using namespace std;

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

    enum HardwareUpdateSource
        {   
            notrequired,
            locally,
            Remotely

        };
    enum hardwareroutineOutput
        {

            ledgreen,
            ledred,
            ledyellow,
            
            ledblue,



        };
#endif