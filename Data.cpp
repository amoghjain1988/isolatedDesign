
    struct GlobalSystemHardware
    {
        int userReq                 :   2;        // 2 bits : 1 bit for True, Second for False.
        int inlineMain              :   2;        // inline as 1 bit size
        int inlinePull              :   2;
        int inlineLift              :   2;
        int ValveMovedRecently      :   2;
  
        int StorageDepth;
        int OverheadDepth;
        int PullMotor               :   2;
        int LiftMotor               :   2;      
        
    };

    GlobalSystemHardware    *HardwareValues = new GlobalSystemHardware;

    struct UserProvidedContants
    {

        const int maxStorageDepth =  200;
        const int minStorageDepth =  20;
        const int maxOverheadDepth =  180;
        const int minOverheadDepth=  20;


    };
    UserProvidedContants    HardwareConstants;