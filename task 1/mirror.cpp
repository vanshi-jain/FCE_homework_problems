//Vanshika Jain
//NUID is 002194103

#include <iostream>
using namespace std;
//no need of function declaration because this is defined before main

void mirror(int* y,int m)
{
    //function doesn't take an array as a whole but as a ptr
    for (int i=0; i< m/2; i++)
    {
        //for loop starts with 0 index and ends with mid size of the array
        int temp= y[i];
        y[i]=y[m-1-i];//swapping
        y[m-1-i]=temp;
    }//works with both even and odd size of array 
}

int main()
{ 
    int l; //size of the array
    cout<<"Enter the length of the array:";
    cin>>l;
    int x[l]; //declaring an array of size l and getting the array inputs from the user
    cout<<"Enter the array:"<<endl;
    for (int i =0; i<l; i++)
    {
        cin>>x[i];
    }
    //calling the function mirror to reverse the array in-place
   mirror(x,l);
   
   cout<<"Mirrored array:"<<endl;
   for (int i=0;i<l;i++)
   {
       cout<<x[i]<<endl;
   }
   return 0;
}
