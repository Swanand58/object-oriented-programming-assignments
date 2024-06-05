#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;


struct tool
{
    int id;
    char name[100];
    int stocks;
    int cost;
};

char filename[] = "tool.data";

void openfile()
{
    fstream file;
    file.open(filename, ios::in);

    if(!file)
    {
        cout<<"\n file does not exist!";
        file.close();
        file.open(filename, ios::out | ios::binary);


        tool t;
        strcpy(t.name,"");
        t.id = 0;
        t.stocks = 0;
        t.cost = 0;

        cout<<"\nCreating empty entry:";
        for(int i=0; i<100; i++)
        {
            file.write((char*) &t, sizeof(t));
        }
        file.close();
        cout<<"\n empty entries created!!";
        
    }
    else
        {
        cout<<endl<<"File Found !!"<<endl<<"Opening File !!"<<endl;
        }
}

void outputLine(ostream &output, tool tool)
{
      output << setiosflags(ios::left) << setw(6) << tool.id
      << setw(20) << tool.name << setw(11) << tool.stocks
      << setiosflags(ios::fixed | ios::showpoint | ios::right)
      << setw(6) << setprecision(2) << tool.cost << endl;
}


void copyData(fstream &infile)
{
    ofstream outfile("print.txt");

    if(!outfile)
    {
        cerr<<"File Not Found !!!";
        return;
    }

    cout<< setiosflags(ios::left) <<
        setw(6) << "ID"<< setw(20)
        << "Name" << setw(11)
        << "Stock"<< setw(6)
        << "Cost" << endl;

    outfile<< setiosflags(ios::left)<<
        setw(6) << "ID"<< setw(20)
        << "Name" << setw(11)
        << "Stock"<< setw(6)
        << "Cost" << endl;

    infile.seekg(0, ios::beg);

    tool tool;

    while(!infile.eof())
    {
        infile.read((char *)&tool, sizeof(tool));

        if(tool.id != 0)
        {
            outputLine(cout, tool);
            outputLine(outfile, tool);
        }
    }

}

void insertRecord(fstream &infile)
{
    int toolnum;
    tool tool;

    cout<<endl<<"Enter New Tool Number: ";
    cin>>toolnum;

    infile.seekg((toolnum-1)*(sizeof(tool)));

    infile.read((char *)&tool, sizeof(tool));
    if(tool.id == 0)
        {
        tool.id = toolnum;
        cout<<endl<<"Enter NEW Tool Name: ";
        cin>>tool.name;

        cout<<endl<<"Enter NEW Tool Stock: ";
        cin>>tool.stocks;

        cout<<endl<<"Enter NEW Tool Cost: ";
        cin>>tool.cost;

        infile.seekp((toolnum-1)*sizeof(tool));
        infile.write((char *)&tool, sizeof(tool));

        cout<<endl<<"Record Inserted at location "<<toolnum<<" ...";
        }
    else
        {
        cerr<<endl<<"Tool Already Exists ..."<<endl<<"Please Try 'Updating Record' ...";
        return;
        }
}

void updateRecord(fstream &infile)
{
    int toolnum;
    tool tool;

    cout<<endl<<"Enter New Tool Number: ";
    cin>>toolnum;

    infile.seekg((toolnum-1)*(sizeof(tool)));

    infile.read((char *)&tool, sizeof(tool));
    if(tool.id != 0)
        {
        tool.id = toolnum;
        cout<<endl<<"Enter NEW Tool Name: ";
        cin>>tool.name;

        cout<<endl<<"Enter NEW Tool Stock: ";
        cin>>tool.stocks;

        cout<<endl<<"Enter NEW Tool Cost: ";
        cin>>tool.cost;

        infile.seekp((toolnum-1)*sizeof(tool));
        infile.write((char *)&tool, sizeof(tool));

        cout<<endl<<"Record Inserted at location "<<toolnum<<" !";
        }
    else
        {
        cerr<<endl<<"Tool Does NOT Exists !"<<endl<<"Please Try 'Inserting Record' !";
        return;
        }
}

void deleteRecord(fstream &infile)
{
    int toolNum;
    tool tool;

    cout<<endl<<"Enter DELETE Tool ID: ";
    cin>>toolNum;

    infile.seekg((toolNum-1)*sizeof(tool));
    infile.read((char *)&tool, sizeof(tool));

    if(tool.id != 0)
    {
        cout<<endl<<"\nDeleting Record!!"<<endl;
        outputLine(cout, tool);

        tool.id = 0;
        strcpy(tool.name, "");
        tool.cost = 0;
        tool.stocks = 0;

        infile.seekp((toolNum-1)*sizeof(tool));
        infile.write((char *)&tool, sizeof(tool));

        cout<<endl<<"\nThe Record is Deleted!!!";
    }
    else
    {
        cerr<<endl<<"Record Does NOT Exist ..."<<endl<<"Cannot Delete ...";
        return;
    }
}

int main()
{
    openfile();

    fstream file(filename, ios::in | ios::out);

    int choice = 0;
    
    while(choice < 5)
        {
            cout<<endl<<"\nMENU\n1. Insert Record\t2. Update Record\t3. Delete Record\t4. Print File\t 5. Exit";
            cout<<endl<<"Enter a Choice ::";
            cin>>choice;

            switch(choice)
                {
                    case 1: insertRecord(file);
                            break;

                    case 2: updateRecord(file);
                            break;

                    case 3: deleteRecord(file);
                            break;

                    case 4: copyData(file);
                            break;

                    case 5: exit(0);
                }
        }
    

    return 0;
}


