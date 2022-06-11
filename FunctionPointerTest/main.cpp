
#include <iostream>


int main()
{
    std::cout<<"\n\t\t\t *****Start of Program*****\n\n";

    base *basePtr = new base();

    basePtr->MakeLinks(new derivedA(1))->MakeLinks(new derivedB(2))->MakeLinks(new derivedC(3));  // This chaining is what creates the next pointer links works. if basepts new line is created then same address is assigned 
    basePtr->Cycle();
    
    delete basePtr; // free doesnt call destructor

    std::cout<<"\n\n\t\t\t *****End of Program****\n";
    return 0;
}