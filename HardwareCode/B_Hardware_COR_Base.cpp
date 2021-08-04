#ifndef B_Hardware_COR_Base
#define B_Hardware_COR_Base


#include <iostream>
#include "A_HardwareData.cpp"




class Hardware{

    public:
  
    virtual Hardware *AddToHWRoutineList(Hardware *nextListItem, HardwareUpdateSource source ) =0;

    virtual Hardware *AddToHWSetupList(Hardware *nextListItem) =0;

    virtual ~Hardware(){};

    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem) =0;

    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source ) =0;



};


class SystemHardware:public Hardware
{

protected:
        Hardware *next = nullptr;
        HardwareUpdateSource sourceLocation;
public:
    virtual ~SystemHardware() { delete next;}

    Hardware * AddToHWRoutineList(Hardware *nextListItem, HardwareUpdateSource source)
    {
        cout<<"\n Added Hardware to List! "<<source;

        next                =   nextListItem;
        sourceLocation      =   source;
        return                  nextListItem;
    }

     virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem) override
    {
         
            cout<<"\n Running Setup for Hardware!!";

            if(this->next)
            {
                return this->next->HardwareSetup(nextSetupItem);
            }
            else
            {                           
                cout<<"\n hardware Setup FInished!!\n.";      
                return false;
            }   
    }   

   
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override
    {

        if(this->next)
        {
            return this->next->HardwareRoutine(myptr, sourceLocation);
        }
        else
        {                           
            cout<<"\n hardware Cycling FInished!!\n.";      
            return false;
        }        
    }


    
};


#endif
