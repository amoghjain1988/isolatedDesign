#include <iostream>
#include <vector>
#include <algorithm>
#include<unistd.h>
unsigned int microsecond = 1000000;

enum TriggerSource
{
    Trig_notset,
    Water_Cyclical,         // when water is found, or any change is detected in globals
    Routine_Cyclical,       // cyclical every 1/2 - 1 hr.
    Time_RTC,               // when rebooting happens @ 1 / every 24 hours
    TrigNotRequired
};

        TriggerSource        TriggerType = Trig_notset;

struct ListBufferItems
{
    TriggerSource   TrigType;
    long            TrigTime;
};
ListBufferItems TrigItem;

    std::vector<ListBufferItems> HW_Trig_Vector;
void HWRoutine(TriggerSource &);

int main()
{
    TrigItem.TrigType = Water_Cyclical;
    TrigItem.TrigTime = 0;
    HW_Trig_Vector.push_back(TrigItem);

    TrigItem.TrigType = Water_Cyclical;
    TrigItem.TrigTime = 2;
    HW_Trig_Vector.push_back(TrigItem);

    TrigItem.TrigType = Routine_Cyclical;
    TrigItem.TrigTime = 13;
    HW_Trig_Vector.push_back(TrigItem);
    
    TrigItem.TrigType = Time_RTC;
    TrigItem.TrigTime = 22;
    HW_Trig_Vector.push_back(TrigItem);

    TrigItem.TrigType = TrigNotRequired;
    TrigItem.TrigTime = 25;
    HW_Trig_Vector.push_back(TrigItem);

    TrigItem.TrigType = Routine_Cyclical;
    TrigItem.TrigTime = 27;
    HW_Trig_Vector.push_back(TrigItem);

        std::cout<<"\n passed 5 values:";


TriggerType  = Routine_Cyclical;
    HWRoutine(TriggerType);
       



}

void HWRoutine(TriggerSource &TriggerType)
{
const auto TriggerPresent =    std::find_if(HW_Trig_Vector.begin(), HW_Trig_Vector.end(), 
                                            [&TriggerType](const ListBufferItems& EventId) 
                                                {   
                                                    std::cout<<"\n Lambda Computing"<< TriggerType;
                                                    return EventId.TrigType == TriggerType; // return TIME..
                                                }

);
if(TriggerPresent!= HW_Trig_Vector.end())
std::cout<<"\n Found Trigger"<<TriggerPresent->TrigTime  ;

}