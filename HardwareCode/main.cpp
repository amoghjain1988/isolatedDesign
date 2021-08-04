
#include "Z_ControllerManager.cpp"


int main(){
    
ControllerManager_t ControllerManager ;


    ControllerManager.HardwareSetup();
    ControllerManager.DeleteHWSetupObject();
    ControllerManager.HardwareRoutineListSetup();
    ControllerManager.HardwareRoutineListCycler();
    ControllerManager.DeleteHWRoutineObject();


return 0;
}