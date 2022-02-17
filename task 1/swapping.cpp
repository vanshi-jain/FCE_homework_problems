//Vanshika Jain
//NUID is 002194103

#include<iostream>
using namespace std;

//return type is null-->void
//function declaration before main function with variable types, names are not necessary
void SwapP(int*, int*);
void SwapR(int&, int&);

int main() //default type of main function is integer
{
    int x,y; 
    cout<<"Enter two numbers:"; //asking the user for inputs
    cin>>x>>y; 
    SwapP(&x,&y); // swap using pointers function is called with parameters as address of variables-->
    cout<<"This is swapping using pointers: "<<x<<" "<<y<<"\n";
    SwapR(x,y);
    cout<<"This is swapping using reference: "<<x<<" "<<y<<endl;
}

void SwapP(int *a, int *b)
{
    //swapping using pointers
    
    int temp=*a;//declaring a new variable with the address of a
    *a=*b; 
    *b=temp; //replacing b with initial value of a stored in temp and a with b
    
}

void SwapR(int& c, int& d )
{
    //swapping using reference
    
    int temp= c;//declaring temp variable with refernce value of c
    c=d; 
    d=temp; //replacing d with value of c and c with d
    
}

