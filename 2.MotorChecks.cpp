#include "1.MotorValidator.cpp"
#include <iostream>

using namespace std;

    class InlineMainandPullCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main + Pull + Recent Valve";
            
            // if(valvePresent());

             if(HwPtr->inlineMain == 1 || HwPtr->inlinePull == 1 || HwPtr->ValveMovedRecently ){
                std::cout<<"\t =>  Yes. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);
             }
             else      
             {
                cout <<"\t => No Water! Exit.";
                return false;
                                   
             }
             
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
             else      
             {
                cout <<"\t => No Water! Exit.";
                return false;

             }
             
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
             else      
             {
                    cout <<"\t => OverheadOverFull. Exit.";
                    return false;

             }
             
        }
    };