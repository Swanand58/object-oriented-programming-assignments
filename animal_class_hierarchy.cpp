#include<iostream>

using namespace std;

class animal
{ 
    public:

    virtual void eat()
    {
        cout<<"****The animal is eating****"<<endl;
    }

};

class dog: public animal
{
    public:

    virtual void eat()
    {
        cout<<"****The dog is eating****"<<endl;
    }
};

class labrador: public animal
{
    public:

    virtual void eat()
    {
        cout<<"****The Labrador is eating****"<<endl;
    }
};

int main()
{
    animal *a, b;
    dog d;
    labrador l;

    a = &b;
    a->eat();

    a = &d;
    a->eat();

    a = &l;
    a->eat();
}

