
#include <iostream>

#include "C_commsObjects.h"

int main()



{

    std::cout<<"\n Starting.. Empty\n";

    commsHandler
    ->CommsItemsCheck(new commsIncoming)
    ->CommsItemsCheck(new commsSetup)
    ->CommsItemsCheck(new commsTimeNTP)
    ->CommsItemsCheck(new commsEspNow)
    ->CommsItemsCheck(new commsAPUser)
    ->CommsItemsCheck(new commsWifi)
    ->CommsItemsCheck(new commsAWS);
    
    *CommStateDesired = offlineAP;
    std::cout<<"\n Looping Through List\n";

    

    commsHandler->CommsChecklist(CommStateDesired);

    std::cout<<"\n Exiting!! Cleaning Objects\n";
    delete commsHandler;
    delete CommStateDesired;
    return 0;
}