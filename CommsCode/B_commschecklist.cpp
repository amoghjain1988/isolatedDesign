#include "A_CommsList.cpp"
#include <iostream>

#define DebugCommsList

class commsIncoming:public CommsParent_Routine
{
    public:
    commsIncoming(){
                std::cout<<"\n Incoming Contructor.";

    }
    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running Comms  Incoming List.";
        #endif

        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsSetup:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsSetup";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsTimeNTP:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsTimeNTP.";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsEspNow:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsEspNow";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsAPUser:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsAPUser";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsWifi:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsWifi.";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};

class commsAWS:public CommsParent_Routine
{
        public:

    virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override
    {
        #ifdef DebugCommsList
        std::cout<<"\n Running commsAWS .";
        #endif
        
        return CommsParent_Routine::CommsChecklist(CommStateCurrent);
        
          
    }
};
