#include <iostream>
#define ThisController 3

       int main()
       {     
        for(int j = 3; j>=0 ; j++) // start from back to erase.
        {   
            if(j== ThisController)
            break;
            
            printf("\n &&&&& inside delete fn with J vallue %d",j);                 
            // if(!ItPeer->ConnectionRequired[j])
            // {   
            //         printf("\n$$$$$$$$ Dleeting Vector at %d", j);
            //     peerStatusList.erase(peerStatusList.begin()+j);
            // }                    
        }


       }