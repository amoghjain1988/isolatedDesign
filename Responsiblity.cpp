    #include <iostream>

    struct GlobalSystemHardware
    {
        int userReq : 2;        // 2 bits : 1 bit for True, Second for False.
        int inline1 : 2;        // inline as 1 bit size
        int inline2 : 2;
        int inline3 : 2;
        int valveCW : 2;
        int valveCCW: 2;
        int StorageDepthMin: 1;
        int StorageDepthMax:1;
        int OverheadDepthMin:1;
        int OverheadDepthMax:1;      

    };



    class MotorValidator{

    public:

    virtual MotorValidator *setNextCheck(MotorValidator *nextCheck) = 0;

    virtual ~MotorValidator(){};

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
    class MotorValidatorCycler: public MotorValidator{

    protected:

        MotorValidator *next = nullptr;
    public:

        ~MotorValidatorCycler(){ delete next;};

        MotorValidator *setNextCheck(MotorValidator *nextCheck){

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



    class InlineMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Check #1 : InlineMain";
             if(HwPtr->inline1>>1 & 1){
                 std::cout<<"\n Inline main Has Water. Motor On.";
                    return false;
             }
             else       // Motor Off
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };

    class InlineTopMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Check #1 : InlineMain";
             if(HwPtr->inline1>>1 & 1){
                 std::cout<<"\n Inline main Has Water. Motor On.";
                    return false;
             }
             else       // Motor Off
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };

    class InlinePullCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Check #2 : InlinePull";
             if(HwPtr->inline1>>1 && 11){
                 std::cout<<"\n Inline 2 Has Water. Motor On.";
                    return false;
             }
             else       // Motor Off
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };
    int main(int argc, char *argv[])

    {
        std::cout<<"\n\n --- Program Start----\n\n";

            GlobalSystemHardware    *HardwareValues = new GlobalSystemHardware;
            //  {0,0,0,0,0,0,0,0,0,0};
            
        MotorValidatorCycler *PullMotorValidator = new MotorValidatorCycler;
        PullMotorValidator->setNextCheck(new InlineMainCheck)->setNextCheck( new InlineTopMainCheck);
        

        HardwareValues->inline1 = 1;      HardwareValues->inline2 = 0;
        std::cout<<"\n Condition #1 for Motor Il1 : "<<HardwareValues->inline1;
        std::cout<<",  Il2 :"<< HardwareValues->inline2;
        // std::cout<<"\n Condition #1 : "<<PullMotorValidator->PullMotorLogic(HardwareValues);


        HardwareValues->inline1 = 0;      HardwareValues->inline2 = 0;
         std::cout<<"\n Condition #2 for Motor Il1 : "<<HardwareValues->inline1;
        std::cout<<",  Il2 : "<< HardwareValues->inline2;
        // std::cout<<"\n Condition #2 : "<<PullMotorValidator->PullMotorLogic(HardwareValues);


        HardwareValues->inline1 = 1;      HardwareValues->inline2= 1;
        std::cout<<"\n Condition #3 for Motor Il1 : "<<HardwareValues->inline1;
        std::cout<<",  Il2 : "<< HardwareValues->inline2;        // std::cout<<"\n Condition #3 : "<<PullMotorValidator->PullMotorLogic(HardwareValues);


        HardwareValues->inline1 = 0;      HardwareValues->inline2= 1;
        std::cout<<"\n Condition #4 for Motor Il1 : "<<HardwareValues->inline1;
        std::cout<<",  Il2 :"<< HardwareValues->inline2;        // std::cout<<"\n Condition #4 : "<<PullMotorValidator->PullMotorLogic(HardwareValues);

        std::cout<<"\n\n --- Program End----\n\n";
        delete PullMotorValidator;
        delete HardwareValues;
        return 0;

    }