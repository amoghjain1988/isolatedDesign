#ifndef eepromStore
#define eepromStore
#include <memory.h>
#include "../statemachines/Admin_SML/sharedPtr.h"

class eeprom_t{

    public:

    template <typename t>
    void Eepromread(const std::shared_ptr<t>);
};

#endif