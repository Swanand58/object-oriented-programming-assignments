#include<iostream>
#include<math.h>
using namespace std;


class Poly
{
    int coeff[20];
    int degree;

    public:
    int readPoly()
    {
        cout<<"\n\nEnter the degree of the polynomial:";
        cin>>degree;
        for(int i=0 ; i<=degree; i++)
        {
            cout<<"Enter the value of co-effecient for x^"<<i<<":  ";
            cin>>coeff[i];
        }


    }
    void display_Polynom()
    {
        cout<<"\nThe entered polynomial is ::";
        for(int i=0 ; i<=degree ; i++)
        {
            if(coeff[i] != 0)
            {
                cout<<coeff[i]<<"x^"<<i<<"+";
            }
        }

    }
    int eval()
    {
        int x, tot=0;

        cout<<"\nEnter the value of x ::";
        cin>>x;

        for(int i; i<=degree; i++)
        {
            tot = tot + coeff[i]*pow(x,degree);  
        }

        cout<<"\n"<<tot;
    }
    int add_polynomial(Poly n)
    {
        Poly temp;
        if(degree >= n.degree)
        {
            temp.degree = degree;
            for(int i=0;i<=degree;i++)
                temp.coeff[i] = coeff[i];

            for(int j=0;j<=degree;j++)
                temp.coeff[j] = temp.coeff[j] + n.coeff[j];    
        }
        else
        {
            temp.degree = n.degree;
            for(int i = 0; i<=n.degree; i++)
            {
                temp.coeff[i] = n.coeff[i];
            }
            for(int j=0; j<=degree; j++)
            {
                temp.coeff[j] = temp.coeff[j] + coeff[j];
            }
        }
        temp.display_Polynom();
    }

    int sub_polynomial(Poly n)
    {
        Poly temp;
        if(degree >= n.degree)
        {
            temp.degree = degree;
            for(int i=0;i<=degree;i++)
                temp.coeff[i] = coeff[i];

            for(int j=0;j<=degree;j++)
                temp.coeff[j] = temp.coeff[j] - n.coeff[j];    
        }
        else
        {
            temp.degree = n.degree;
            for(int i = 0; i<=n.degree; i++)
            {
                temp.coeff[i] = n.coeff[i];
            }
            for(int j=0; j<=degree; j++)
            {
                temp.coeff[j] = temp.coeff[j] - coeff[j];
            }
        }
        temp.display_Polynom();

    }
    void multiPoly(Poly n)
    {
        Poly temp;
        temp.degree = degree + n.degree - 1;
        for(int i = 0; i<temp.degree; i++)
        {
            temp.coeff[i] = 0;
        }
        for(int j = 0; j<degree; j++)
        {
            for(int k = 0; j < n.degree; k++)
            {
                temp.coeff[j+k] += coeff[j] +n.coeff[k];
            }
        }
        temp.display_Polynom();
    }

};

int main()
{

    Poly p1,p2;

    p1.readPoly();
    p1.display_Polynom();

    p2.readPoly();
    p2.display_Polynom();

    p1.add_polynomial(p2);

    p1.sub_polynomial(p2);
    
    p1.multiPoly(p2);
    p1.eval();
    
    
}


