#include <iostream>

int main()
{
    char *str = new char[20];

    delete char* str;
    delete str[];
    delete [] str;

    delete *str;

    delete str[20];
}