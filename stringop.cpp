#include<iostream>
#include<string.h>

using namespace std;

class string1
{
    char str[100];
    int length;

    public:
            void read_str()
            {
                cout<<"\nEnter the string ::";
                cin>>str;
                length = strlen(str);
            }

            void print_str()
            {
                cout<<"\n\nThe string entered is "<<str<<endl;
            }

            string1 operator+(string1 s)
            {
                string1 t;

                strcpy(t.str,str);
                strcat(t.str,s.str);
                t.length = length + s.length;
                return t;
            }

            int operator==(string1 s)
            {
                if(strcmp(str,s.str) == 0)
                  return 1;
                else  
                  return 0;
            }
};
int main()
{
    string1 s1,s2,s3;
    s1.read_str();
    s2.read_str();
    s1.print_str();
    s2.print_str();
    s3 = s1 + s2;

    if(s1==s2)
       cout<<"\n\nBOTH THE STRINGS ARE THE SAME !!";
    else
       cout<<"\n\nBOTH THE STRINGS ARE DIFFERENT !!";

    
    s3.print_str();

       
}