#ifndef comms
#define comms

#include "sharedPtr.h"


class Communications
{ // Sends

public:
         void doWork(std::shared_ptr<EventCallback>meraPointer);
};

#endif
