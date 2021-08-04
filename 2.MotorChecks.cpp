#include "1.MotorValidator.cpp"
#include <iostream>


// Set by Hardware Class!

bool valvePresent(){
return true;

}

bool PullMotorPresent(){

return true;
}


using namespace std;



    class InlinePullCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Valve";
        
        if(PullMotorPresent())
            {

                if(HwPtr->ValveMovedRecently ){
                    std::cout<<"\t =>  Yes. Next CHeck!";
                    return MotorValidatorCycler::PullMotorLogic(HwPtr);
                }
                
                cout <<"\t => No Valve! Exit.";
                return false;

            }
            
        std::cout<<"\t =>  Skip Valve. Next CHeck!";
        return MotorValidatorCycler::PullMotorLogic(HwPtr);                                                             
        }
    };


    class InlineMainPullValveCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main + Pull + Recent Valve";            

             if(HwPtr->inlineMain == 1 || HwPtr->inlinePull == 1 || HwPtr->ValveMovedRecently ){
                std::cout<<"\t =>  Yes. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);
             }
             
                cout <<"\t => No Water! Exit.";
                return false;
                                   
             
             
        }
    };


    class InlineMainCheck:public MotorValidatorCycler{
    // no valve based systems.
    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main";            

             if(HwPtr->inlineMain == 1 ){
                std::cout<<"\t =>  Yes. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);
             }
             
                cout <<"\t => No Water! Exit.";
                return false;
                                   
             
             
        }
    };

    class InlineLiftCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Inline Lift";
             if(HwPtr->inlineLift==1){
                std::cout<<"\t =>  Yes. Next CHeck!";
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back


             }
            
                cout <<"\t => No Water! Exit.";
                return false;

             
             
        }
    };

      class StorageDepthCheck:public MotorValidatorCycler{

        public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Storage Depth";
             if(HwPtr->StorageDepth > HardwareConstants.minStorageDepth){
                std::cout<<"\t =>  Yes. Next CHeck!";
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return A Pointer to Feed Next

             }
             else      
             {
                cout <<"\t => StorageOverFull! Exit.";
                return false;
             }
             
        }
    };


      class OverheadDepthCheck:public MotorValidatorCycler{

        public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking Min Overhead Depth";
             if(HwPtr->OverheadDepth > HardwareConstants.minOverheadDepth){
                 std::cout<<"\t Yes. Next CHeck.";
                    return MotorValidatorCycler::PullMotorLogic(HwPtr);    
                    
             }
            
            cout <<"\t => OverheadOverFull. Exit.";
            return false;

             
             
        }
    };