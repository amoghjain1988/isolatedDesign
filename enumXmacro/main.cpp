#include <iostream>

#define ExecFunctio \
X(started) \
X(botted)\
X(poweresent)\
X(notuyetSet)\
X(ReadtoSleep)


#define X(execlist) e_##execlist,   // can write another list usign ##
enum Exec_Enum{
    ExecFunctio
};
#undef X

int main()
{
   
 

    #define X(execlist) std::cout<<"\n "<<#execlist;
    ExecFunctio
    #undef X
    
    Exec_Enum ExecObject = e_notuyetSet;
    std::cout<<"\n "<<ExecObject;

    return 0;

}