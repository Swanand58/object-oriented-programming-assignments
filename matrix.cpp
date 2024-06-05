//using matrix operations and sparse matrix using oop concepts
//option 1 add,opt 2 subtract , opt 3 multiply , ot 4 div , isSparse , create compact matrix

//implement c++ program based on set opertions using oop concepts
//union 
//intersection
//subtraction

#include<iostream>
#include<conio.h>
using namespace std;

class matrix
{
    int a = 3; 
    int b = 3;
    int M[3][3];
    int compactMatrix[3][3];

    public:
    void readMatrix()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                cout<<"\n\nEnter the number for "<<i<<" & "<<j<<" position :\n\n";
                cin>>M[i][j];
            }
        }
    }
    void displayMatrix()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                cout<<" "<<M[i][j];
            }
            cout<<endl;
            cout<<"\n";
        }    
    }
    void matrixAdd(matrix x , matrix y)
    {
        a = x.a;
        b = x.b;
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                M[i][j] = x.M[i][j]+y.M[i][j];
            }
        }
        //cout<<endl<<"matrix added...\n";
    
    }
    void matrixSub(matrix x , matrix y)
    {
        a = x.a;
        b = x.b;
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                M[i][j] = x.M[i][j]-y.M[i][j];
            }
        }
    
    }
    void matrixMult(matrix x , matrix y)
    {
        a = x.a;
        b = x.b;

        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                M[i][j] = 0.0;
                for(int k = 0 ; k < b ; k++)
                {
                    M[i][j] += x.M[i][k] * y.M[k][j];
                }
            }

        }       

    }
    void isSparseMatrix()
    {
        int zeros = 0;
        if(zeros > (a*b)/2)
        {
            cout<<"The matrix is a sparse matrix\n";
            sparseMatrix();
        }
        else
        {
            cout<<"The matrix is not a sparse matrix\n";
        }
            
    }
    
    void sparseMatrix()
    {
        int k = 0; 
        for (int i = 0; i < 4; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                if (M[i][j] != 0) 
                { 
                    compactMatrix[0][k] = i; 
                    compactMatrix[1][k] = j; 
                    compactMatrix[2][k] = M[i][j]; 
                    k++; 
                }
            }
        }         
    
        for (int i=0; i<3; i++) 
        { 
            for (int j=0; j<k; j++) 
                printf("%d ", compactMatrix[i][j]); 
    
            printf("\n"); 
        } 

    }
   
};
int main()
{
    matrix m1,m2,m3;
    m1.readMatrix();
    m2.readMatrix();
    m1.displayMatrix();
    m2.displayMatrix();
    cout<<"\n Addition of matrices \n";
    m3.matrixAdd(m1,m2);
    m3.displayMatrix();
    cout<<"\n Subtracton of matrices \n";
    m3.matrixSub(m1,m2);
    m3.displayMatrix();
    cout<<"\n Multiplication of matrices \n";
    m3.matrixMult(m1,m2);
    m3.displayMatrix();
    m1.isSparseMatrix();
    m2.isSparseMatrix();


    return 0;
}