#include<iostream>
using namespace std;


class complex
{
    private:
    int real,imaginary;

    public:

    complex()
    {
        real = 0;
        imaginary = 0;
    }
    complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    complex(int n)
    {
        real = n;
        imaginary = n;
    }

    complex(complex &x)
    {
        real = x.real;
        imaginary = x.imaginary; 
    }
    void show()
    {
            cout<<endl<<real<<" + "<<imaginary<<"i";
    }
    int getreal()
    {
        return real;
    }
    int getimaginary()
    {
        return imaginary;
    }
    int set(int a , int b)
    {
        real = a;
        imaginary = b;
    }
};

int main()
{
    complex c1(12,14), c2(10), c4;
    complex c3(c1);
    int a, b;
    cout<<endl<<"Complex number 1 is : ";
    c1.show();

    cout<<endl<<"Complex number 2 is : ";
    c2.show();

    cout<<endl<<"Complex number 3 is : ";
    c3.show();

    cout<<endl<<"Real value of complex number 4 is :"<<c4.getreal();
    

    cout<<endl<<"Imaginary value of complex number 4 is :"<<c4.getimaginary();
    

    cout<<endl<<"Enter the real value ::";
    cin>>a;
    cout<<endl<<"Enter the imaginary value ::";
    cin>>b;

    c4.set(a,b);

    c4.show();
    return 0;
}

