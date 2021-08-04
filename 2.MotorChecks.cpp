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
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Valve";
        
        if(PullMotorPresent())
            {

                if(HwPtr->ValveMovedRecently ){
                    std::cout<<"\t =>  Yes. Next CHeck!";
                    return MotorValidatorCycler::MotorLogic(HwPtr);
                }
                
                cout <<"\t => No Valve! Exit.";
                return false;

            }
            
        std::cout<<"\t =>  Skip Valve. Next CHeck!";
        return MotorValidatorCycler::MotorLogic(HwPtr);                                                             
        }
    };


    class InlineMainPullValveCheck:public MotorValidatorCycler{

    public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main + Pull + Recent Valve";            

             if(HwPtr->inlineMain == 1 || HwPtr->inlinePull == 1 || HwPtr->ValveMovedRecently ){
                std::cout<<"\t =>  Yes. Next CHeck!";
                 return MotorValidatorCycler::MotorLogic(HwPtr);
             }
             
                cout <<"\t => No Water! Exit.";
                return false;
                                   
             
             
        }
    };


    class InlineMainCheck:public MotorValidatorCycler{
    // no valve based systems.
    public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {
        
        std::cout<<"\n Checking: Inline Main";            

             if(HwPtr->inlineMain == 1 ){
                std::cout<<"\t =>  Yes. Next CHeck!";
                 return MotorValidatorCycler::MotorLogic(HwPtr);
             }
             
                cout <<"\t => No Water! Exit.";
                return false;
                                   
             
             
        }
    };

    class InlineLiftCheck:public MotorValidatorCycler{

    public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Inline Lift";
             if(HwPtr->inlineLift==1){
                std::cout<<"\t =>  Yes. Next CHeck!";
                return MotorValidatorCycler::MotorLogic(HwPtr);       // return the same pointer back

             }            
                cout <<"\t => No Water! Exit.";
                return false;

             
             
        }
    };

      class StorageDepthCheck:public MotorValidatorCycler{

        public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {
            std::cout<<"\n Checking Storage Depth";
             if(HwPtr->StorageDepth > HardwareConstants.minStorageDepth){
                std::cout<<"\t =>  Yes. Next CHeck!";
                return MotorValidatorCycler::MotorLogic(HwPtr);       // return A Pointer to Feed Next

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
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking Min Overhead Depth";
             if(HwPtr->OverheadDepth > HardwareConstants.minOverheadDepth){
                 std::cout<<"\t Yes. Next CHeck.";
                    return MotorValidatorCycler::MotorLogic(HwPtr);    
                    
             }
            
            cout <<"\t => OverheadOverFull. Exit.";
            return false;

             
             
        }
    };
      class RunTimeCheck:public MotorValidatorCycler{
          // Determines if Motor Can Run During thiS time..
        public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking Motor Run Time Check";
             if(HardwareConstants.Starthour < mytime->currentHour && 
             HardwareConstants.CloseHour > mytime->currentHour){
                 std::cout<<"\t Yes. Next CHeck.";
                    return MotorValidatorCycler::MotorLogic(HwPtr);    
                    
             }
            
            cout <<"\t => User Requested Quiet TIme. Exit.";
            return false;

             
             
        }
    };

     class CoolDownTimeCheck:public MotorValidatorCycler{
          // Determines if Motor Can Run During thiS time..
        public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking If Motor is under coolDOwn.";
             if(lastRuntime->lastPullMotorOntime + HardwareConstants.LiftMCoolDownTIme < mytime->currentHour){
                 std::cout<<"\t Yes. Next CHeck.";
                    return MotorValidatorCycler::MotorLogic(HwPtr);    
                    
             }
            
            cout <<"\t => Pull Motor in cool Down State.. Exit.";
            return false;

             
             
        }
    };

      class MorningParallelDuty:public MotorValidatorCycler{
          // Determines if Motor Can Run During thiS time..
        public:
        bool MotorLogic(GlobalSystemHardware *HwPtr) override {

            std::cout<<"\n Checking If Motor is under coolDOwn.";
             if(lastRuntime->lastPullMotorOntime + HardwareConstants.LiftMCoolDownTIme < mytime->currentHour){
                 std::cout<<"\t Yes. Next CHeck.";
                    return MotorValidatorCycler::MotorLogic(HwPtr);    
                    
             }
            
            cout <<"\t => Pull Motor in cool Down State.. Exit.";
            return false;

             
             
        }
    };