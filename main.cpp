    #include <iostream>

    #include "2.MotorChecks.cpp"




  void printHarwareValues()
    {
        cout <<"\n "<<" Current HW Status";
        cout<<"\n 1. inlineMain         : "<<HardwareValues->inlineMain;
        cout<<"\n 2. inlinePull         : "<<HardwareValues->inlinePull;
        cout<<"\n 3. inlineLift         : "<<HardwareValues->inlineLift;
        cout<<"\n 4. ValveMovedRecently : "<<HardwareValues->ValveMovedRecently;        
        cout<<"\n 7. StorageDepth       : "<<HardwareValues->StorageDepth;
        cout<<"\n 8. OverheadDepth     : "<<HardwareValues->OverheadDepth;
         
    }

    void SetHwValues(bool b,bool c,bool d,bool e,int h,int i)
    {
        HardwareValues->inlineMain               =b;
        HardwareValues->inlinePull               =c;
        HardwareValues->inlineLift               =d;
        HardwareValues->ValveMovedRecently       =e;        

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
        ->setNextCheck(new InlineMainandPullCheck)
        ->setNextCheck(new StorageDepthCheck)
        ->setNextCheck(new OverheadDepthCheck);

        


        
        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #1 : ";
        SetHwValues(1,0,1,0,123,23);
        printHarwareValues();
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";


        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #2 : ";
        SetHwValues(1,0,1,0,15,23);
        printHarwareValues();
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";


        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #3 : ";
        SetHwValues(0,0,1,1,15,23);
        printHarwareValues();
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";


        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #4 : ";
        SetHwValues(1,0,0,0,45,23);
        printHarwareValues();
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";



        std::cout<<"\n\n -----------------------\n\n";
        std::cout<<"\n Condition #5 : ";
        SetHwValues(1,0,0,0,45,123);
        printHarwareValues();
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";



        std::cout<<"\n\n --- Program End----\n\n";


        delete PullMotorValidator;
        delete HardwareValues;
        return 0;

    }