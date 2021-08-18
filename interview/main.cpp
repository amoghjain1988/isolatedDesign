
class XXX{
    public :
    int memberfunc();
};


class YYY : public XXX{
    public :
    int memberfunc();
};

int main()
{
    XXX *bptr = new YYY;
    YYY *dptr;

    dptr = dynamic_cast<XXX*>(bptr);
        dptr = static_cast<YYY*>(bptr);
        dptr = dynamic_cast<YYY*>(bptr);
        dptr = dynamic_cast<YYY*>(bptr);

}