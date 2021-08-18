#include <iostream>

template <class T> class Some
{
    public:
    static int stat;
};

template<class T>
int Some<T>::stat = 10;

int main()
{
    Some<int>::stat= 5;
    std::cout<<Some<int>::stat <<"";
        std::cout<<Some<char>::stat <<"";
    std::cout<<Some<float>::stat <<"";
    std::cout<<Some<long>::stat <<"";

}