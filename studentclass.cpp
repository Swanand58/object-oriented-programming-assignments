#include<iostream>
#include<cstring>
using namespace std;

class Student
{
    int roll;  //roll number of a student in this class
    int m1,m2,m3,m4,m5; //marks of 5 subjects of the students
    char *name,*grade,*class_stud; //char pointer for dynamic allocation of space for name,grade and class 
    float percent; //percentage that the student got

    public:
            Student(int r , const char *n , int a , int b , int c , int d , int e )
            {
                roll = r;
                m1 = a;
                m2 = b;
                m3 = c;
                m4 = d;
                m5 = e;
                name = new char[2];
                strcpy(name,n);
                grade = new char[1];
                class_stud = new char[2];
                percent = 0.0;                
            }
            
            ~Student()
            {
                delete name;
                delete grade;
                delete class_stud;
            }
          

            void calc_per()
            {
                 percent = (m1 + m2 + m3 + m4 + m5)/5;
                 cout<<"\nThe Percentage acquired by the student is :"<<percent<<"%";
               
            }

            void calc_grade()
            {
                if(percent <= 90)
                {
                    strcpy(grade,"A+");
                }
                else if(75 < percent < 89)
                {
                    strcpy(grade,"A");
                }
                else if(65 < percent < 74)
                {
                    strcpy(grade,"B");
                }
                else if(40 < percent < 65)
                {
                    strcpy(grade,"C");
                }
                else
                {
                    strcpy(grade,"FAIL");
                }
                
                cout<<"\nThe Grade acquired by the student is :"<<grade;
            }

            void calc_classstud()
            {
                if(percent>=75 && percent<100)
                {
                    strcpy(class_stud,"First Class with Distinction");
                }
                else if(percent>60 && percent<75)
                {
                    strcpy(class_stud,"First Class");
                }
                else
                {
                    strcpy(class_stud,"Second Class");
                }
                cout<<"\nThe Class of the student is :"<<class_stud;
            }
            void Display()
            {
                cout<<"\nThe Name of the student is :"<<name;
                cout<<"\nThe Rollno of the student is :"<<roll;
                cout<<"\nThe marks of the student in subject 1 is  :"<<m1<<"\nThe marks of the student in subject 2 is  :"<<m2<<"\nThe marks of the student in subject 3 is  :"<<m3<<"\nThe marks of the student in subject 4 is  :"<<m4<<"\nThe marks of the student in subject 5 is  :"<<m5;
                
            }

};
int main()
{
    int r;
    Student s1(35 , "Swanand" ,92 , 91, 90, 93, 94 );
      
    s1.Display();   
    s1.calc_per();
    s1.calc_grade();
    s1.calc_classstud();
   
}