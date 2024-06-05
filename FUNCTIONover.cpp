#include <iostream> 
using namespace std; 
  
void show(int n) 
{ 
  cout << "\n\noverloading here is int " << n; 
} 
void show(double  m) 
{ 
  cout << "\n\noverloading here is float " << m; 
} 
void show(char const *p) 
{ 
  cout << "\n\noverloading here is char* " << p; 
} 
  
int main() 
{ 
  show(26); 
  show(26.26); 
  show("twenty six"); 
  
}