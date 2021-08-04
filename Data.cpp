
    struct GlobalSystemHardware
    {
        int userReq                 :   2;        // 2 bits : 1 bit for True, Second for False.
        int inlineMain              :   2;        // inline as 1 bit size
        int inlinePull              :   2;
        int inlineLift              :   2;
        int ValveMovedRecently      :   2;
        int valveCW                 :   2;
        int valveCCW                :   2;
        int valveSwitchedRecently   :   2;
        int StorageDepthMin         :   2;
        int StorageDepthMax         :   2;
        int OverheadDepthMin        :   2;
        int OverheadDepthMax        :   2;
        int PullMotor               :   2;
        int LiftMotor               :   2;      
        
    };
