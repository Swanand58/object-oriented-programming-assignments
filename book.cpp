#include<iostream>
#include<iomanip>
using namespace std;

class book
{
    int book_id;
    string book_name;
    string author;
    double cost;

    public:
    static double total;
    void getdetails()
    {
        cout<<"\nEnter the bookid :";
        cin>>book_id;
        cout<<"\nEnter the book name :";
        cin>>book_name;
        cout<<"\nEnter the author name :";
        cin>>author;
        cout<<"\nEnter the cost :";
        cin>>cost;
        total = total + cost;
        
    }
    void printdetails()
    {
        cout<<"\nBook ID :: "<<book_id;
        cout<<"\nBook Name :: "<<book_name;
        cout<<"\nAuthor Name :: "<<author;
        cout<<"\nCost of the Book :: "<<cost;
        cout<<"\n\n";
         

    }   
    

   
};
double book::total=0;

int main()
{
    int a;
    
    cout<<"\n\nEnter the number of books you want :\n\n";
    cin>>a;

    book *B;
    B = new book[a];
  

    for(int i = 0 ; i<a ; i++)
    {
         B[i].getdetails();
    }
    for(int i = 0 ; i<a ; i++)
    {
         B[i].printdetails();
    }
   
    cout<<"The Total cost of books ::"<<book::total<<"\n"; 
}