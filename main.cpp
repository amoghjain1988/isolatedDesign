#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include <time.h>


// #include <libpq-fe.h>


// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
int main()
{
    std::cout<<"\n\n..... Program Starting ........\n";

    std::cout << "\ncurrentDateTime()=" << currentDateTime() << std::endl;

    // getchar();  // wait for keyboard input
    std::cout<<"\n\n Program Shutting down\n\n";

    return 0;
}

