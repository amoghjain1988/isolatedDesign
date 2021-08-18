#include <iostream>

template <class T>
void StringConst( T arg)
{
    typename std::remove_const<T>::type new_arg;

    if(std::is_const< decltype (new_arg) > :: value)
    std::cout<<"\n type of new arg is const";

    else
    {
    std::cout<<"\n type of new arg is NOT const";
    }

}


int main()

{
    StringConst("blinkin");
        StringConst(676);

    StringConst(3.14);

}