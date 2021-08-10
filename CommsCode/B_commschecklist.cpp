#include "B_commschecklist.h"
#include <iostream>

#define DebugCommsList


    void commsIncoming::CommsChecklist(communicationStates_t *CommStateCurrent)
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running Comms  Incoming List.";
        #endif

        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }



     void commsSetup::CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsSetup List Class";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }


    void commsTimeNTP::CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsTimeNTP.";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
              
    }


    void commsEspNow::CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsEspNow";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }

    void commsAPUser::CommsChecklist(communicationStates_t *CommStateCurrent)
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsAPUser";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }

    void commsWifi::CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsWifi.";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }

    void commsAWS::CommsChecklist(communicationStates_t *CommStateCurrent) 
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsAWS .";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }

