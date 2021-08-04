#ifndef C_HardwareSetup
#define C_HardwareSetup
#include "B_Hardware_COR_Base.cpp"
//#include input pins



class relayPullSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Pull ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};
class relayLiftSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Lift ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};

class LEDSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HE Setup :  LEDSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};

class SDCardSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  SDCardSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};


class BtnSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : BtnSetup";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};

class DepthStorageSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  DepthStorageSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};


class InlineMainSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  Relay Pull ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};
class InlinePullSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  InlinePullSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};


class InlineValveSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  InlineValveSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};


class ValveSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : ValveSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};
class BmsStorageSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup : BmsStorageSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};

class BMSOverheadSetup: public SystemHardware
{
    public:
    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem)  override{

            std::cout<<"\n HW Setup :  BMSOverheadSetup ";
            return SystemHardware::HardwareSetup(nextSetupItem);

    }
};
#endif
