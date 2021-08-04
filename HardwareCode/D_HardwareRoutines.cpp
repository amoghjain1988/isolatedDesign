#include "B_Hardware_COR_Base.cpp"
#include "./relay/B_MotorChecks.cpp"
using namespace std;


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
class PowerSettings: public SystemHWRoutine
{
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: PowerSettings  :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);

    }
};
class relayPull: public SystemHWRoutine
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



        delete PullMotorValveValidator;

        delete HardwareValues;


    }
            return SystemHWRoutine::HardwareRoutine(myptr, source);

    }

};


class relayLift: public SystemHWRoutine
{
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: RElay Lift src  :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);

    }
};


class DepthStorage: public SystemHWRoutine
{
        public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: Depth ST src    :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);

    }
};


class DepthOverhead: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

            std::cout<<"\n Checking: Depth OH src    :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class LED: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: LED src         :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};

class UserButton: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: UserButton src  :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class SDCard: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: SDCard src      :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class RTC: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: RTC src         :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class Valve: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: Valve src       :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class BMSOverhead: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSOverhead src :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};
class BMSStorage: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSStorage src  :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};

class PowerAndSleep: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: PowerAndSleep src:"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class InlineMain: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: InlineMain src  :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadPull: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking:IL_OHPull src    :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadLift: public SystemHWRoutine
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking:IL_OHLift src    :"<<source;
                   return SystemHWRoutine::HardwareRoutine(myptr, source);
    }

};