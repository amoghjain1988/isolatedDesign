
#include <iostream>
#include "A_CommsList.h"

    communicationStates_t *CommStateDesired = new communicationStates_t;




  
   CommsParent_Setup  *CommsParent_Routine::CommsItemsCheck(CommsParent_Setup *nextItem) 
    {
        next = nextItem;
        return nextItem;
        std::cout<<"\n Added Item to Comms List ";
    }

    void CommsParent_Routine:: CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        if(this->next)
        {
            return this->next->CommsChecklist(CommStateCurrent);
        }
        else
        {   
            #ifdef Dbg_HW_ListRoutine                        
            std::cout<<"\n Exiting Comms Current State!!\n.";   
            #endif 

        }   
    }
    

