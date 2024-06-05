#include<iostream>
#include<fstream>
using namespace std;

class book
{
    protected:
    int book_id;
    char book_name[100];
    char author[100]; 
    double cost;

    public:
   
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
       
        
    }
    int getb_id()
    {
        return book_id;
    }
    char* get_author()
    {
        return author; 
    }
    char* get_bookname()
    {
        return book_name;
    }
    int get_cost()
    {
        return cost;
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

class bookdetails : public book
{
    public:

    void storetofile()
    {
        fstream outputfile;
        outputfile.open("file.txt",ios::out);
        outputfile<<getb_id()<<endl;
        outputfile<<get_bookname()<<endl;
        outputfile<<get_author()<<endl;
        outputfile<<get_cost()<<endl;
        
        
        outputfile.close();
    }
    void getfromfile()
    {
        ifstream infile;
        infile.open("file.txt");
        cout<<"Reading file from files:";
        infile >> book_id;
        cout<<endl<<book_id;
        infile >> book_name;
        cout<<endl<<book_name;
        infile >> author;
        cout<<endl<<author;
        infile >> cost;
        cout<<endl<<cost;
    }

};

int main()
{
    bookdetails b1;
    
    b1.getdetails();
    b1.printdetails();
    b1.storetofile();
    b1.getfromfile();
    return 0; 
}
