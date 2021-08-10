#ifndef B_commschecklist
#define B_commschecklist
#include "A_CommsList.h"
#include <iostream>

#define DebugCommsList

    class commsIncoming:public CommsParent_Routine
    {
        public:        
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsSetup:public CommsParent_Routine
    {        
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsTimeNTP:public CommsParent_Routine
    {
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsEspNow:public CommsParent_Routine
    {
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsAPUser:public CommsParent_Routine
    {
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsWifi:public CommsParent_Routine
    {
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };

    class commsAWS:public CommsParent_Routine
    {
        public:
        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
    };


#endif
