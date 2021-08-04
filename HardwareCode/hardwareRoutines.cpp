#include "hardware.cpp"
using namespace std;

class relayPull: public SystemHardware
{ 
    
    
        public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

        std::cout<<"\n Checking: RElay Pull src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);

    }

};


class relayLift: public SystemHardware
{
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

        std::cout<<"\n Checking: RElay Lift src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);

    }
};


class DepthStorage: public SystemHardware
{
        public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

        std::cout<<"\n Checking: Depth Storage src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);

    }
};


class DepthOverhead: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: Depth Overhead src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class LED: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: LED src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};

class UserButton: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: UserButton src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class SDCard: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: SDCard src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class RTC: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: RTC src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class Valve: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: Valve src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class BMSOverhead: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSOverhead src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};
class BMSStorage: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: BMSStorage src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};

class PowerAndSleep: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: PowerAndSleep src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineMain: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: InlineMain src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadPull: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: InlineOverheadPull src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};


class InlineOverheadLift: public SystemHardware
{ 
            public:
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

           std::cout<<"\n Checking: InlineOverheadLift src"<<source;
                   return SystemHardware::HardwareRoutine(myptr, source);
    }

};