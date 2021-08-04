    #include <iostream>
    using namespace std;

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
            else
            {
                           
                cout<<"\n No More next";      
                return true;

            }
            
        }
    };



    class InlineMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Check #1 : InlineMain";
        
             if(HwPtr->inlineMain == 1){
                std::cout<<"\t Inline Main Has Water. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);
             }
             else      
             {
                cout <<"\\t Inline Main doens have Water ";
                return false;
                                   
             }
             
        }
    };

    class InlineTopMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Check #2 : Inline Top";
            
            if(HwPtr->inlinePull == 1){
                 std::cout<<"\t Inline TOp Has Water. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);            // return the same pointer back

             }
             else                                                               // Motor Off
             {
                cout <<"\t Inline Top doens have Water. ";
                return false;
             }
             
        }
    };

    class InlinePullCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Check #3 : InlinePull";
             if(HwPtr->inlineLift==1){
                 std::cout<<"\n Inline 3 Has Water. Motor On.";
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

        bool motorOutput;
        std::cout<<"\n\n --- Program Start----\n\n";

            GlobalSystemHardware    *HardwareValues = new GlobalSystemHardware;
            //  {0,0,0,0,0,0,0,0,0,0};
            
        MotorValidatorCycler *PullMotorValidator = new MotorValidatorCycler;
        PullMotorValidator->setNextCheck(new InlineMainCheck)->setNextCheck( new InlineTopMainCheck);
        

        HardwareValues->inlineMain = 1;      HardwareValues->inlinePull = 0;
        std::cout<<"\n Condition #1 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 :"<< HardwareValues->inlinePull;
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 0;      HardwareValues->inlinePull = 0;
         std::cout<<"\n Condition #2 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 : "<< HardwareValues->inlinePull;
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;        
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 1;      HardwareValues->inlinePull= 1;
        std::cout<<"\n Condition #3 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 : "<< HardwareValues->inlinePull;        
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 0;      HardwareValues->inlinePull= 1;
        std::cout<<"\n Condition #4 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 :"<< HardwareValues->inlinePull;        
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        
        std::cout<<"\n\n --- Program End----\n\n";
        delete PullMotorValidator;
        delete HardwareValues;
        return 0;

    }