#ifndef A_CommsList 
#define A_CommsList 


    #include <iostream>
    enum communicationStates_t
    {
    offlineAP,
    online_OTA,
    online_AWS,
    sleep,
    };


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

    
        virtual CommsParent_Setup *CommsItemsCheck(CommsParent_Setup *nextItem) override;

        virtual void CommsChecklist(communicationStates_t *CommStateCurrent) override;
        

    };


#endif
