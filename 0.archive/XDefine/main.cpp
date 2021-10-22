#include <iostream>
#include "newheader.cpp"

const char* convertEnumToString(Exec_Enum Obj)
{
       switch(Obj)
        {
            #define X(execlist)  \
            case execlist: 
            std::cout<<"\n Returning :"<<#execlist; 
            return #execlist; break;
            ExecFunctio
            #undef X

            default :
            std::cout<<"\n Default Called";
            break;
        }
}

int main()
{
   
 
    std::cout<<"\n Auto Print all------------";

    #define X(execlist) std::cout<<"\n "<<execlist;
    ExecFunctio
    #undef X
    
    Exec_Enum ExecObject = notuyetSet;
    std::cout<<"\n Harccoded object"<<ExecObject;

    for(int i = started; i <= ReadtoSleep; i++)
    {
        ExecObject= static_cast<Exec_Enum>(i);
        
        std::cout<<"\n Value of Enum" << i << " is " <<convertEnumToString(ExecObject);
   
    }



    return 0;
std::cout<<"\n Exiting Program";
}

