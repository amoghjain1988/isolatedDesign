
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
