


#include <iostream>
#include "1.hardwaredata.cpp"

using namespace std;
  enum HardwareUpdateSource
    {   
        notrequired,
        locally,
        Remotely

    };

class Hardware{

    public:
  
    virtual Hardware *AddToHWList(Hardware *nextListItem, HardwareUpdateSource source ) =0;

    virtual ~Hardware(){};

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

    Hardware * AddToHWList(Hardware *nextListItem, HardwareUpdateSource source){
         cout<<"\n Added HW to list with Srouce "<<source;
            next = nextListItem;
            sourceLocation = source;
            return nextListItem;
    }

    virtual bool HardwareRoutine(GlobalHWData *myptr, HardwareUpdateSource source) override{

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

