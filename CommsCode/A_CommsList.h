#ifndef A_CommsList 
#define A_CommsList 


    #include <iostream>

    enum communicationStates_t
    {
        offlineAP,
        online_RouterOnly,
        online_Router_AWSCloud,     
        online_Temp,  
        online_Cellular_AWScloud,   // routine checks have less time in btw
        sleep,
    };
    communicationStates_t *CommStateDesired = new communicationStates_t;


    class CommsParent_Setup
    {
        public:
        virtual ~CommsParent_Setup(){};

        virtual CommsParent_Setup *CommsItemsCheck(CommsParent_Setup *nextItem ) = 0;

        virtual void CommsChecklist(communicationStates_t *) = 0 ;
        
    };

    class CommsParent_Routine : public CommsParent_Setup
    {
        protected:

        CommsParent_Setup *next = nullptr;

        public:
        
        virtual ~CommsParent_Routine(){
        delete next;
        }

    
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
            std::cout<<"\n Exiting Comms Current State!!\n.";   
            #endif 

        }   
        }
        

    };


#endif
