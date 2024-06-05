#include<iostream>
using namespace std;

class A
{
    private:
    int m;
    public:
    A()
    {
        cout<<"In class A\n";
        m = 100;
    }
    friend class B;
    
};
class B
{
    private:
    int n;
    public:
      void showA(A& x) 
    { 
        cout<<"In class B\n";
        cout<<"\nm="<<x.m; 
    } 
}; 
  
int main() 
{ 
    A a; 
    B b; 
    b.showA(a); 
    return 0; 
}
