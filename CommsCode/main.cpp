
#include <iostream>

#include "C_commsObjects.cpp"

int main()



{

    // unique_ptr<> ;
	// 	std::unique_ptr<communicationStates_t> CommStateDesired = std::make_unique<communicationStates_t>();


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

    commsHandler->CommsChecklist(CommStateDesired);

    std::cout<<"\n Rturning Empty\n";
    delete commsHandler;
    delete CommStateDesired;
    return 0;
}