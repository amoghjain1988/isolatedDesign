#ifndef B_Hardware_COR_Base
#define B_Hardware_COR_Base


#include <iostream>
#include "A_HardwareData.cpp"




class Hardware{

    public:
  
    virtual Hardware *AddToHWList(Hardware *nextListItem, HardwareUpdateSource source ) =0;

    virtual ~Hardware(){};

    virtual bool HardwareSetup(GlobalHWData *myptr, HardwareUpdateSource source ) =0;

    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source ) =0;
    // virtual bool GetRemoteHardwareValues(GlobalHWData * )=0;
    // virtual void SetHardwareTriggers(GlobalHWData * )=0;


};


class SystemHardware:public Hardware
{

protected:
        Hardware *next = nullptr;
        HardwareUpdateSource sourceLocation;
public:
    virtual ~SystemHardware() { delete next;}

    Hardware * AddToHWList(Hardware *nextListItem, HardwareUpdateSource source)
    {
        cout<<"\n Added Hardware to List! "<<source;
        next = nextListItem;
        sourceLocation = source;
      //  nextListItem->HardwareSetup();
        return nextListItem;
    }

     virtual bool HardwareSetup(GlobalHWData *myptr, HardwareUpdateSource source ) override
    {
         
            cout<<"\n Running Setup for Hardware!! "<<source;

            if(this->next){
            return this->next->HardwareSetup(myptr, sourceLocation);
            }
            else
            {                           
                cout<<"\n hardware Setup FInished!!\n.";      
                return false;
            }   
    }   


   
    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override
    {

        if(this->next){
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
