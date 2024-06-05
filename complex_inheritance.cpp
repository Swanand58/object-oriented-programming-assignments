#include<iostream>
using namespace std;


class complex
{
    protected:
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

class complexop : public complex
{ 
        static int count;
        public:

        static void increment_count();
        static void display_count();
        
        complexop() : complex()
        {
                increment_count();
        }
        complexop(int a) : complex(a)
        {
                increment_count();
        }
        complexop(int a, int b) : complex(a,b)
        {   
                increment_count();
        }
        complexop(complexop &x) : complex(x)
        {
                increment_count();
        }

        complexop operator+(complexop a)
        {
            complexop temp;
            temp.real = real + a.getreal();
            temp.imaginary = imaginary + a.getimaginary();

            return temp;
        }

        complexop operator-(complexop a)
        {
            complexop temp;
            temp.real = real - a.getreal();
            temp.imaginary = imaginary - a.getimaginary();

            return temp;
        }

        complexop operator*(complexop a)
        {
            complexop temp;
            temp.real = real * a.getreal();
            temp.imaginary = imaginary * a.getimaginary();

            return temp;
        }


};
int complexop::count;

void complexop::increment_count()
{
    count++;
}
void complexop::display_count()
{
    cout<<endl<<"count is "<<count;
}

int main()
{
    complexop c1(12,14), c2(10), temp, temp1,temp2;
    
    temp = c1 + c2;
    temp.show();

    temp1 = c1 - c2;
    temp1.show();

    temp2 = c1 * c2;
    temp2.show();

    complexop::display_count();
    
    return 0;
}

