    #include <iostream>

    #include "2.MotorChecks.cpp"




  void printHarwareValues()
    {
        cout <<"\n "<<" Current HW Status";
        cout<<"\n 1. UserReq            : "<<HardwareValues->userReq;
        cout<<"\n 2. inlineMain         : "<<HardwareValues->inlineMain;
        cout<<"\n 3. inlinePull         : "<<HardwareValues->inlinePull;
        cout<<"\n 4. inlineLift         : "<<HardwareValues->inlineLift;
        cout<<"\n 5. ValveMovedRecently: "<<HardwareValues->ValveMovedRecently;        
        cout<<"\n 6. valveCW            : "<<HardwareValues->valveCW;
        cout<<"\n 7. valveCCW          : "<<HardwareValues->valveCCW; 
        cout<<"\n 8. StorageDepthn    : "<<HardwareValues->StorageDepth;
        cout<<"\n 10. OverheadDepth   : "<<HardwareValues->OverheadDepth;
  
       
    }

    void SetHwValues(bool a, bool b,bool c,bool d,bool e,bool f,bool g,bool h,bool i)
    {
         HardwareValues->userReq                 =a;
        HardwareValues->inlineMain               =b;
        HardwareValues->inlinePull               =c;
        HardwareValues->inlineLift               =d;
        HardwareValues->ValveMovedRecently       =e;        
        HardwareValues->valveCW                  =f;
        HardwareValues->valveCCW                 =g; 
        HardwareValues->StorageDepth             =h;
        HardwareValues->OverheadDepth            =i;

    }
    
    int main(int argc, char *argv[])

    {

        
        bool motorOutput;
        std::cout<<"\n\n --- Program Start----\n\n";

            //  {0,0,0,0,0,0,0,0,0,0};
            
        MotorValidatorCycler *PullMotorValidator = new MotorValidatorCycler;
        PullMotorValidator
        ->setNextCheck(new InlineMainCheck)
        ->setNextCheck( new InlinePullCheck);
        // ->setNextCheck()
        

        HardwareValues->inlineMain = 1;
        HardwareValues->inlinePull = 0;
        HardwareValues->ValveMovedRecently =1;
        
        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #1 : ";
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";






        std::cout<<"\n\n --- Program End----\n\n";


        delete PullMotorValidator;
        delete HardwareValues;
        return 0;

    }