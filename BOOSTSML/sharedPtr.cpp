 #include "sharedPtr.h"

#include <memory>

std::shared_ptr<EventCallback>myptr = std::make_unique<EventCallback>();
