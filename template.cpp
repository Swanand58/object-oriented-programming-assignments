#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> v;
    cout<<"\n initial size="<<v.size()<<" \n ";

    int x;
    int n;
    cout<<"\n enter how many values ::";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\n enter values :: ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"\n\n size after inserting values : "<<v.size();

    cout<<"\n\n current contents : ";
    display(v);

    v.push_back(2);

    cout<<"\n\n size after push_back = "<<v.size()<<"\n";
    cout<<"\n\n now the contents of vector after push_back() ::";
    display(v);

    cout<<"\n\n iterator created and inserted element at 3rd position ";
    vector<int>::iterator itr1=v.begin();
    itr1=itr1+2;
    v.insert(itr1,1,6);

    cout<<"\n\n contents of vector after inserting :";
    display(v);
    cout<<"\n\n removing elements 3rd and 4th position::";
    
    v.erase(v.begin()+2,v.begin()+4);
    cout<<"\n\n contents after deletion :";
    display(v);
    cout<<"\n\n";
    return 0;

   }