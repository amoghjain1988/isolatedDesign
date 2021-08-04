#include "1.MotorValidator.cpp"
#include <iostream>

using namespace std;

    class InlineMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main";
        
             if(HwPtr->inlineMain == 1 || HwPtr->ValveMovedRecently){
                std::cout<<"\t Inline Main Has Water. Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);
             }
             else      
             {
                cout <<"\\t Inline Main doens have Water ";
                return false;
                                   
             }
             
        }
    };

    class InlinePullCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking Inline Pull @ Top";
            
            if(HwPtr->inlinePull == 1 || HwPtr->ValveMovedRecently){
                 std::cout<<"\t Inline Top + Valve Moved Recent Check.Next CHeck!";
                 return MotorValidatorCycler::PullMotorLogic(HwPtr);            // return the same pointer back

             }
             else                                                               // Motor Off
             {
                cout <<"\t Inline Top doens have Water. ";
                return false;
             }
             
        }
    };

    class InlineLiftCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Inline Lift";
             if(HwPtr->inlineLift==1){
                 std::cout<<"\n Inline Lift Has Water. Motor On.";
                    return false;
             }
             else      
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };

      class StorageDepthCheck:public MotorValidatorCycler{

        public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Min Storage Depth";
             if(HwPtr->StorageDepth > HardwareConstants.minStorageDepth){
                 std::cout<<"\n Storage Tank Less than Full. Motor On.";
                    return false;
             }
             else      
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };


      class OverheadDepthCheck:public MotorValidatorCycler{

        public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Min Overhead Depth";
             if(HwPtr->OverheadDepth > HardwareConstants.minOverheadDepth){
                 std::cout<<"\n Overhead Tank Less than Full. Motor On.";
                    return false;
             }
             else      
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };