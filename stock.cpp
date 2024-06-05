#include<iostream>
#include<iomanip>
using namespace std;

class book
{
    protected:
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
        
        addcost(cost);
        
    }
    void printdetails()
    {
        cout<<"\nBook ID :: "<<book_id;
        cout<<"\nBook Name :: "<<book_name;
        cout<<"\nAuthor Name :: "<<author;
        cout<<"\nCost of the Book :: "<<cost;
        cout<<"\n\n";
    }   

    static void addcost(int);
};
class stock : public book
{
    protected:

    int stock;
    float total_price;
    static int grand_total;

    public:
    void getstock()
    {
        cout<<"\n\n Enter the stock present for current book :";
        cin>>stock;

        total_price = stock * cost;
        addtotcost(total_price);
    }
    void show()
    {
        cout<<"\n\n "<<book_id<<"\t"<<book_name;
    }
    static void addtotcost(int);
    static void showgrandtot();
    static void showtotal();

};
double book :: total = 0;
int stock :: grand_total = 0;


void book :: addcost(int c)
{
    total = total+c;
}
void stock :: showtotal()
{
    cout<<"\n\ntotal cost of all book :"<<total;
}
void stock :: addtotcost(int c)
{
    grand_total = grand_total + c;
}
void stock :: showgrandtot()
{
    cout<<"\n\n grand total cost of all books is :"<<grand_total;
}
int main()
{
    stock *s;
    s = new stock[3];

    for(int i = 0 ; i<3 ; i++)
    {
         s[i].getdetails();
         s[i].getstock();
    }
    for(int i = 0 ; i<3 ; i++)
    {
         s[i].show();
    }
   
    stock :: showtotal();
    stock :: showgrandtot();
    return 0;   
}