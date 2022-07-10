#ifndef eepromStore
#define eepromStore
#include <memory.h>
#include "../statemachines/Admin_SML/sharedPtr.h"

class eeprom_event_bubbler{

    public:

    template<typename t>
    void eventBubbler(std::shared_ptr<t>sptr);
};

#endif