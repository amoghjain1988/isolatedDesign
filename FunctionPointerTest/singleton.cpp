#include "singleton.h"


mySingleton* mySingleton::myInstance = 0;

mySingleton* mySingleton::createInstance(){

    if(!myInstance){
        myInstance = new mySingleton();
    }

    return myInstance;
}

int mySingleton::returnValue() {
            
                return x++;
}

mySingleton::mySingleton(){
    createInstance();
}