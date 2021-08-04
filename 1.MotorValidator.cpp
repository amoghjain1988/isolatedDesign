
    #include <iostream>
    #include "Data.cpp"
    using namespace std;


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
                cout<<"\n All Checks Passed! Motor ON.";      
                return true;
            }
            
        }
    };
