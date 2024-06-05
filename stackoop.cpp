#include<iostream>

using namespace std;

class stack
{
    public:
            int max;
            int *a;
            int top;

        stack()
        {
            cout<<"IN CONSTRUCTOR 1\n";
            max = 5;
            a = new int[5];
            top = -1;
        }

        stack(int x)
        {
            cout<<"IN CONSTRUCTOR 2\n";
            max = x;
            a = new int[x];
            top = -1;

        }
        void push(int n)
        {
            if(!isFull())
            {
                a[++top] = n;
                cout<<"ELEMENT PUSHED \n"; 
            }
            else
            {
                cout<<"\n\nStack is full cannot push ";
            }
                
        }
        int pop()
        {
            if(!isEmpty())
            {
                int var = a[top];
                top--;
                cout<<"ELEMENT POPPED\n";
                return var;
            }
            else
            {
                cout<<"\nCannot pop stack empty ";
            }
            

        }
        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
                
        }
        bool isFull()
        {
            if(top == max)
                return true;
            else 
                return false;    
        }

};

int main()
{
    stack s1(5);

    s1.push(36);
    s1.push(3);
    s1.push(1);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

}

