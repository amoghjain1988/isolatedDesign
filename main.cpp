


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
      const char end[2] = "";


   char *token;
   token = strtok(inputString, s);
    while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
      

        return 0;


    }