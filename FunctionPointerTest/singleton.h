#ifndef SINGLETON
#define SINGLETON

class mySingleton
{

    private:
        int x = 5;
        static mySingleton* myInstance;
        //mySingleton();
    public:

        static mySingleton* createInstance();

        int returnValue();
      

        void setValue(int y)
        {
            x  = y;
        }

};

#endif
