


    #include <iostream>
#include <string.h>
#include <stdio.h>

    char inputString[30] = "[false,true,true,false]";
    // char inputString[30] = "temp123";

    int main()
    {
        char    *SignalA;
        char    SignalB[7];
        char    SignalC[7];
        char    SignalD[7];

 
   const char s[4] = "[,]";


   char *token;
   token = strtok(inputString, s);

// printf("\n first token : %s", token);
int i = 0;


    while( token != NULL ) {
      printf( "\nCount #%d %s",i, token );
    
      token = strtok(NULL, s);
      i++;
   }
      

        return 0;


    }