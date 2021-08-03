    #include <iostream>

    struct GlobalSystemHardware
    {
        int userReq : 2;        // 2 bits : 1 bit for True, Second for False.
        int inline1 : 2;        // inline as 1 bit size
        int inline2 : 2;
        int inline3 : 2;
        int valveCW : 2;
        int valveCCW: 2;
        int StorageDepthMin: 2;
        int StorageDepthMax:2;
        int OverheadDepthMin:2;
        int OverheadDepthMax:2;      

    };

    GlobalSystemHardware    *HardwareValues  = {};


    class MotorStateValidator{

    public:

    virtual MotorStateValidator *setNextCheck(MotorStateValidator *nextCheck) = 0;

    virtual ~MotorStateValidator(){};

    virtual bool PullMotorLogic(GlobalSystemHardware *) =0;


    };

    /*
        Class Excepts the a Pointer to GLobal Hardware Struct

        if first Validation Check Passes, Others are performed.
        
        We go through Entire Chain, and Soon as A  False is Encountered we Stop Motor.
        These are AutoMated Checks. 

        User-> inlineMain->InlineTop->DepthStorage->depthOH

        While(ChainOfEvents)
        {
            if(true)
            checkNext
                if ALL TRUE : TurnMotorOn
                else 
                MotorOff
        }

    */
    class MotorValidator: public MotorStateValidator{

    protected:

        MotorStateValidator *next = nullptr;
    public:

        ~MotorValidator(){ delete next;};

        MotorStateValidator *setNextCheck(MotorStateValidator *nextCheck){

            next = nextCheck;
            return nextCheck;
        }

        virtual bool  PullMotorLogic(GlobalSystemHardware *HwPtr) override
        {
            if(this->next){
                return this->next->PullMotorLogic(HwPtr);
            }
            return false;
        }
    };



    class InlineMainCheck:public MotorValidator{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Check #1 : InlineMain";
             if(HwPtr->inline1>>1 && 11){
                 std::cout<<"\n Inline1 Set True";

             }
            return true;
        }
    };

    int main()

    {


        std::cout<<"\n Checks for Motor \n";

        return 0;

    }