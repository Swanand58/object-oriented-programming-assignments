#include<iostream>
#include<conio.h>
using namespace std;
class Set
{
    int a[15],n;
    public:
    Set(){}
    Set(int x)
    {
        this->n = x;
    }
    void operator <(Set s2)
    {
        Set s3;
    }
    void get()
    {
        cout<<"\n\nEnter the Set Values :";
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort();
    }
    
    void sort()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
                }
            }
        }        
    }

    void show()
    {
        for(int i=0;i<n;i++,cout<<"  ")
        cout<<a[i];
    }   

    void operator +(Set s2)
    {
        // int unions[30];
        //cout<<"Here ";


        Set s3;
        int i=0,j=0,k;
        for(k=0;i<n && j<s2.n;k++)
        {
            if(a[i]==s2.a[j])
            {
                s3.a[k]=a[i++];
                j++;
            }
            else if(a[i]<s2.a[j])
                s3.a[k]=a[i++];
            
            else
                s3.a[k]=a[j++];
        }
        while(i<n)
        s3.a[k++]=a[i++];
        
        while(j<s2.n)
        s3.a[k++]=s2.a[j++];
        
        cout<<"\n\nA U B  :: ";
        s3.n=k;
        s3.show();
    }
    void operator -(Set s2)
    {
        Set s3;
        int i=0,j=0,k=0;
        for(i=0;i<n;i++)
        {
            for (j = 0; j < s2.n; j++)
            {
                if(a[i]==s2.a[j])
                    s3.a[k++]=a[i];
            }
        }
        cout<<"\n\nA INTERSECTION B  ::";
        s3.n=k;
        s3.show();
    }
};

int main()
{

    int n,n1;
    cout<<"\nSET OPERATIONS";
    cout<<"\nEnter No.of elements in Set A & B : ";
    cin>>n;
    cin>>n1;

    Set s1(n),s2(n1),s3;
    s1.get();
    s2.get();
    
    cout<<"\nSet A  ::";
    s1.show();
    cout<<"\nSet B  ::";
    s2.show();
    s1+s2; //union
    s1-s2;//intersection
return 0;
}