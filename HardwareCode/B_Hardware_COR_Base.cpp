#ifndef B_Hardware_COR_Base
#define B_Hardware_COR_Base


#include <iostream>
#include "A_HardwareData.cpp"




class Base_Hardware_Routine{

    public:
  
    virtual Base_Hardware_Routine *AddToHWRoutineList(Base_Hardware_Routine *nextListItem, HardwareUpdateSource source ) =0;


    virtual ~Base_Hardware_Routine(){};


    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source ) =0;



};

class Base_Hardware_Setup{

    public:
  

    virtual Base_Hardware_Setup *AddToHWSetupList(Base_Hardware_Setup *nextListItem) =0;

    virtual ~Base_Hardware_Setup(){};

    virtual bool HardwareSetup(HWSetupInitializers *nextSetupItem) =0;




};


class SystemHardwareSetup:public Base_Hardware_Setup
{

protected:
        Base_Hardware_Setup *next = nullptr;

public:
    virtual ~SystemHardwareSetup() { delete next;}
      virtual Base_Hardware_Setup *AddToHWSetupList(Base_Hardware_Setup *nextListItem)
      {
        cout<<"\n Added Hardware to Setup List! ";

        next                =   nextListItem;
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
};


class SystemHWRoutine:public Base_Hardware_Routine
{

protected:
        Base_Hardware_Routine *next = nullptr;
        HardwareUpdateSource sourceLocation;
public:
    virtual ~SystemHWRoutine() { delete next;}

    Base_Hardware_Routine * AddToHWRoutineList(Base_Hardware_Routine *nextListItem, HardwareUpdateSource source)
    {
        cout<<"\n Added Hardware to List! "<<source;

        next                =   nextListItem;
        sourceLocation      =   source;
        return                  nextListItem;
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
