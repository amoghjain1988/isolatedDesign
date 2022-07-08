
#include <iostream>
//#include "CommsList.cpp"

class abstract{ 
        public:
        virtual abstract *MakeLinks(abstract *) =0;
        virtual void Cycle() =0;
         abstract(){ std::cout<<"\n abstract constructor";}
        ~ abstract(){ std::cout<<"\n abstract destructor";}

};

class base:public abstract{
    public:
        base(){ std::cout<<"\n\t base constructor intval: "<<baseInteger;}
       ~ base(){ std::cout<<"\n\t base destructor"<<baseInteger;}

    protected:
        abstract *next = NULL;
        int baseInteger = 0;

    public:
      
        abstract *MakeLinks(abstract *NewObject) override{
            next = NewObject;
            std::cout<<"\n\t address of next:"<<&next;
            return next;
    }

    void Cycle ()override{

        if(this->next)
            this->next->Cycle();
    }

};

class derivedA : public base{

public:
        derivedA(int x){ baseInteger = x; std::cout<<"\n\t\t derivedA constructor";}
      ~ derivedA(){ std::cout<<"\n\t\t derivedA destructor";}

    void Cycle ()override{
        std::cout<<"\n\t\t Doing Derived A Thing intval: "<<baseInteger;
        return base::Cycle();
    }

};

class derivedB : public base{
    public:
        derivedB(int x ){ baseInteger = x; std::cout<<"\n\t\t derivedB constructor";}
      ~ derivedB(){ std::cout<<"\n\t\t derivedB destructor";}

    void Cycle ()override{
        std::cout<<"\n\t\t Doing Derived B Thing intval:"<<baseInteger;
        return base::Cycle();
    }

};

class derivedC : public base{
   public:
        derivedC(int x){ baseInteger = x; std::cout<<"\n\t\t\t derivedC constructor";}
      ~ derivedC(){ std::cout<<"\n\t\t derivedC destructor";}

    void Cycle ()override{
        std::cout<<"\n\t\t Doing Derived C Thing intval: "<<baseInteger;
        return base::Cycle();
    }

};
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