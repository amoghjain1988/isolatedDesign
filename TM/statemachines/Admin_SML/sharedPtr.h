#ifndef sharedPtr
#define sharedPtr
#include <memory>


class  EventCallback;   // Forward declartion - to be used in Main.cpp, and below to make pointers


// defined in StateTable class
// adding extern prvents state table to access teh variable/.strange..
std::shared_ptr<EventCallback>pReturnEvent;     // provides access to Object in Main to


#endif
