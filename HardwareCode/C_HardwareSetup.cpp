#ifndef C_HardwareSetup
#define C_HardwareSetup
#include "B_Hardware_COR_Base.cpp"
//#include input pins

class PowerSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : PowerSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};

class relayPullSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Pull ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};
class relayLiftSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Lift ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};

class LEDSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HE Setup :  LEDSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};

class SDCardSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  SDCardSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};


class BtnSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : BtnSetup";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};

class DepthStorageSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  DepthStorageSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};


class InlineMainSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Pull ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};
class InlinePullSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  InlinePullSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};


class InlineValveSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  InlineValveSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};


class ValveSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : ValveSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};
class BmsStorageSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : BmsStorageSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};

class BMSOverheadSetup: public SystemHardwareSetup
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  BMSOverheadSetup ";
            return SystemHardwareSetup::HardwareSetup(nextSetupItem);

    }
};
#endif
