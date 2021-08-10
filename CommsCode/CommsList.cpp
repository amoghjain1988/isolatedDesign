
#include <iostream>
enum communicationStates_t
{
offlineAP,
online_OTA,
online_AWS,
sleep,
};
communicationStates_t *CommStateDesired;


class CommsParent_Setup
{
    public:
    ~ CommsParent_Setup(){};
    virtual void *CommsItemsCheck(CommsParent_Setup*nextItem ) = 0;

    virtual void CommsChecklist(communicationStates_t *)  = 0;
    
};

class CommsParent_Routine : public CommsParent_Setup
{
    protected:

    CommsParent_Setup *next = nullptr;
    public:
    
    ~CommsParent_Routine(){delete next;};

    void *CommsItemsCheck(CommsParent_Setup *nextItem) override
    {
        next = nextItem;
        return nextItem;
    }

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
            if(this->next)
            {
                return this->next->CommsChecklist(CommStateCurrent);
            }
            else
            {   
                #ifdef Dbg_HW_ListRoutine                        
                std::cout<<"\n Exisint Comms Current State!!\n.";   
                #endif 

                // return CommStateDesired;
            }   
    }
    

};