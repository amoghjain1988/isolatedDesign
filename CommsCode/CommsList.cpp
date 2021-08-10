
#include <iostream>
enum communicationStates_t
{



};
communicationStates_t *CommStateDesired;
communicationStates_t *CommStateCurrent;


class CommsParent_Setup
{
    public:
    ~ CommsParent_Setup(){};
    virtual void *CommsItemsCheck(CommsParent_Setup*nextItem ) = 0;

    virtual communicationStates_t* CommsChecklist(communicationStates_t *)  = 0;
    
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
    
    communicationStates_t* CommsChecklist(communicationStates_t *) override
    {

    }
    

};