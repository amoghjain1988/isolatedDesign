#include <iostream>

#define ExecFunctio \
X(started) \
X(botted)\
X(poweresent)\
X(notuyetSet)\
X(ReadtoSleep)

// #define X(execlist) e_##execlist,   // to change events throughtout..


#define X(execlist) execlist,   // can write another list usign ##
enum Exec_Enum{
    ExecFunctio
};
#undef X

const char* convertEnumToString(Exec_Enum Obj)
{
       switch(Obj)
        {
            #define X(execlist)  \
            case execlist: std::cout<<"\n Returning :"<<#execlist; return #execlist; break;
            ExecFunctio
            #undef X

            default :
            std::cout<<"\n Default Called";
            break;
        }
}

int main()
{
   
 

    #define X(execlist) std::cout<<"\n "<<#execlist;
    ExecFunctio
    #undef X
    
    Exec_Enum ExecObject = notuyetSet;
    std::cout<<"\n "<<ExecObject;

    for(int i = started; i <= ReadtoSleep; i++)
    {
        ExecObject= static_cast<Exec_Enum>(i);
        
        std::cout<<"\n Value of Enum" << i << " is " <<convertEnumToString(ExecObject);
   
    }



    return 0;
std::cout<<"\n Exiting Program";
}

