    #include <iostream>
    #include "Data.cpp"

    #include "2.MotorChecks.cpp"


    int main(int argc, char *argv[])

    {

        bool motorOutput;
        std::cout<<"\n\n --- Program Start----\n\n";

            GlobalSystemHardware    *HardwareValues = new GlobalSystemHardware;
            //  {0,0,0,0,0,0,0,0,0,0};
            
        MotorValidatorCycler *PullMotorValidator = new MotorValidatorCycler;
        PullMotorValidator->setNextCheck(new InlineMainCheck)->setNextCheck( new InlineTopMainCheck);
        

        HardwareValues->inlineMain = 1;      HardwareValues->inlinePull = 0;
        std::cout<<"\n Condition #1 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 :"<< HardwareValues->inlinePull;
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 0;      HardwareValues->inlinePull = 0;
         std::cout<<"\n Condition #2 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 : "<< HardwareValues->inlinePull;
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;        
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 1;      HardwareValues->inlinePull= 1;
        std::cout<<"\n Condition #3 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 : "<< HardwareValues->inlinePull;        
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        std::cout<<"\n\n -------\n\n";


        HardwareValues->inlineMain = 0;      HardwareValues->inlinePull= 1;
        std::cout<<"\n Condition #4 for Motor Il1 : "<<HardwareValues->inlineMain;
        std::cout<<",  Il2 :"<< HardwareValues->inlinePull;        
        motorOutput = PullMotorValidator->PullMotorLogic(HardwareValues);
        std::cout<<"\n Motor Output: "<<motorOutput;
        
        std::cout<<"\n\n --- Program End----\n\n";
        delete PullMotorValidator;
        delete HardwareValues;
        return 0;

    }