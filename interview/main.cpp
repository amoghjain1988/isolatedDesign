#include <iostream>
#include <vector>

enum TriggerSource
{
    Trig_notset,
    Water_Cyclical,         // when water is found, or any change is detected in globals
    Routine_Cyclical,       // cyclical every 1/2 - 1 hr.
    Time_RTC,               // when rebooting happens @ 1 / every 24 hours
    TrigNotRequired
};

        TriggerSource        TriggerType;

struct ListBufferItems
{
    TriggerSource   TrigType;
    long            TrigTime;
};

    std::vector<ListBufferItems> HW_Trig_Vector;
void HWRoutine(TriggerSource &);

int main()
{
        TriggerType = Water_Cyclical;       HWRoutine(TriggerType   );
        TriggerType = Time_RTC;             HWRoutine(TriggerType   );
        TriggerType = Water_Cyclical;       HWRoutine(TriggerType   );
        TriggerType = Routine_Cyclical;     HWRoutine(TriggerType   );
        TriggerType = Routine_Cyclical;     HWRoutine(TriggerType   );


}

void HWRoutine(TriggerSource &TriggerType)
{
const auto TriggerPresent =    std::find(HW_Trig_Vector.begin(), HW_Trig_Vector.end(), [&TriggerType](const ListBufferItems& EventId) {
        return EventId.TrigType == TriggerType;
}
)

}