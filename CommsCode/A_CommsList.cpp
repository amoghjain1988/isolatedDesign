
#include <iostream>
enum communicationStates_t
{
offlineAP,
online_OTA,
online_AWS,
sleep,
};
communicationStates_t *CommStateDesired = new communicationStates_t;


class CommsParent_Setup
{
    public:
    ~ CommsParent_Setup(){};
    virtual CommsParent_Setup *CommsItemsCheck(CommsParent_Setup *nextItem ) = 0;

    virtual void CommsChecklist(communicationStates_t *)  = 0;
    
};

class CommsParent_Routine : public CommsParent_Setup
{
    protected:

    CommsParent_Setup *next = nullptr;
    public:
    
    ~CommsParent_Routine(){
        std::cout<<"\n Derived Class Destructor \n \n";
        delete next;
        };

  
    virtual CommsParent_Setup *CommsItemsCheck(CommsParent_Setup *nextItem) override
    {
        next = nextItem;
        return nextItem;
        std::cout<<"\n Added Item to Comms List ";
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