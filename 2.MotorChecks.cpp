#include "1.MotorValidator.cpp"
#include <iostream>

using namespace std;

    class InlineMainCheck:public MotorValidatorCycler{

    public:
        bool PullMotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Check #1 : Inline Main";
        
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

            std::cout<<"\n Check #2 : Inline Pull @ Top";
            
            if(HwPtr->inlinePull == 1 || HwPtr->ValveMovedRecently){
                 std::cout<<"\t Inline TOp Has Water. Next CHeck!";
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
            std::cout<<"\n Check #3 : Inline Lift";
             if(HwPtr->inlineLift==1){
                 std::cout<<"\n Inline 3 Has Water. Motor On.";
                    return false;
             }
             else       // Motor Off
             {
                return MotorValidatorCycler::PullMotorLogic(HwPtr);       // return the same pointer back
                                                                    // calling the virtual fn above will make
                                                                    // call to the next class
             }
             
        }
    };