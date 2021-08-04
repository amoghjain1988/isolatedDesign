#include "hardware.cpp"
using namespace std;
#include "./relay/B_MotorChecks.cpp"
 void SetHwValues(bool b,bool c,bool d,bool e,int h,int i)
    {
        HardwareValues->inlineMain               =b;
        HardwareValues->inlinePull               =c;
        HardwareValues->inlineLift               =d;
        HardwareValues->ValveMovedRecently       =e;        

        HardwareValues->StorageDepth             =h;
        HardwareValues->OverheadDepth            =i;

    }
      void printHarwareValues()
    {
        cout <<"\n "<<" Current HW Status";
        cout<<"\n 1. W-Main : "<<HardwareValues->inlineMain;
        cout<<", 2. W-Pull  : "<<HardwareValues->inlinePull;
        cout<<", 3. WlLift  : "<<HardwareValues->inlineLift;
        cout<<", 4. ValRec  : "<<HardwareValues->ValveMovedRecently;        
        cout<<", 7. StDepth : "<<HardwareValues->StorageDepth;
        cout<<", 8. OvDepth : "<<HardwareValues->OverheadDepth;
         
    }
class relayPull: public SystemHardware
{ 
    
    
        public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: RElay Pull src  :"<<source;
    if(source == locally)
    {


        bool motorOutput;


        MotorValidatorCycler *PullMotorValveValidator = new MotorValidatorCycler;
            PullMotorValveValidator
            ->setNextCheck(new RunTimeCheck)
            ->setNextCheck(new InlineMainPullValveCheck)
            ->setNextCheck(new StorageDepthCheck)
            ->setNextCheck(new OverheadDepthCheck);
            


        
        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #1 : ";
        SetHwValues(1,0,1,0,123,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->MotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";


        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #2 : ";
        SetHwValues(1,0,1,0,15,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->MotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";


        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #3 : ";
        SetHwValues(0,0,1,1,15,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->MotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";

        delete PullMotorValveValidator;

        delete HardwareValues;


    }
            return SystemHardware::HardwareRoutine(myptr, source);

    }

};


class relayLift: public SystemHardware
{
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: RElay Lift src  :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);

    }
};


class DepthStorage: public SystemHardware
{
        public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: Depth ST src    :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);

    }
};


class DepthOverhead: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: Depth OH src    :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class LED: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: LED src         :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};

class UserButton: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: UserButton src  :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class SDCard: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: SDCard src      :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class RTC: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: RTC src         :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class Valve: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: Valve src       :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class BMSOverhead: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSOverhead src :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};
class BMSStorage: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSStorage src  :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};

class PowerAndSleep: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: PowerAndSleep src:"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineMain: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: InlineMain src  :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadPull: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking:IL_OHPull src    :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadLift: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking:IL_OHLift src    :"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};