    #include <iostream>

    #include "2.MotorChecks.cpp"




  void printHarwareValues()
    {
        cout <<"\n "<<" Current HW Status";
        cout<<"\n 1. W-Main : "<<HardwareValues->inlineMain;
        cout<<", 2. W-Pull  : "<<HardwareValues->inlinePull;
        cout<<", 3. WlLift  : "<<HardwareValues->inlineLift;
        cout<<", 4. ValRec  : "<<HardwareValues->ValveMovedRecently;        
        cout<<", 7. StDepth : "<<HardwareValues->StorageDepth;
        cout<<", 8. OvDepth : "<<HardwareValues->OverheadDepth;
         
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


         // lift motor wud have differnet sequence to be added from another class!
         /*
                Most COmplicated : Pull + Lift + Valve
                Normal  : Lift + Pull
                Easy :      Lift

                Other COmbination : Lift + Valve... yeah..maybe kriti?

                Just adjust the Flow and Calls Below.

         */


        MotorValidatorCycler *PullMotorValveValidator = new MotorValidatorCycler;
        PullMotorValveValidator
        ->setNextCheck(new RunTimeCheck)

        ->setNextCheck(new InlineMainPullValveCheck)
        ->setNextCheck(new StorageDepthCheck)
        ->setNextCheck(new OverheadDepthCheck);


        // cyle through all, order is relevant, just efficient, as it helps exits first.
        MotorValidatorCycler *LiftMotorValidator = new MotorValidatorCycler;
        LiftMotorValidator
        ->setNextCheck(new RunTimeCheck)
        ->setNextCheck(new CoolDownTimeCheck)
        ->setNextCheck(new InlineMainPullValveCheck)
        ->setNextCheck(new StorageDepthCheck)
        ->setNextCheck(new OverheadDepthCheck);
        


        
        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #1 : ";
        SetHwValues(1,0,1,0,123,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";


        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #2 : ";
        SetHwValues(1,0,1,0,15,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";


        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #3 : ";
        SetHwValues(0,0,1,1,15,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";


        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #4 : ";
        SetHwValues(1,0,0,0,45,23);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n --- Program End----\n\n";



        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #5 : ";
        SetHwValues(1,0,0,0,45,123);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";

        std::cout<<"\n --- Program End----\n\n";
        std::cout<<"\n Condition #5 : ";
        SetHwValues(1,0,0,0,300,123);
        printHarwareValues();
        motorOutput = PullMotorValveValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -----------------------\n\n";


        std::cout<<"\n --- Program End----\n\n";

        delete PullMotorValveValidator;
        delete LiftMotorValidator;
        delete HardwareValues;
        return 0;

    }