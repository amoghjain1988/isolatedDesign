#ifndef comms
#define comms

#include "sharedPtr.h"

class Communications
{ // Sends

public:
        template<typename sharedPtrMainClass>
         void doWork(std::shared_ptr<sharedPtrMainClass>meraPointer);
};

#endif
