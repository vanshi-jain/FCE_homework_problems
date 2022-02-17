//Vanshika Jain
//Nuid is 002194103

#include<iostream>
#include<limits>
#include<climits>
#include<cstdlib>
using namespace std;

void merge(int a[],int p, int q, int r)
{
    if (a[q]<=a[q+1]) // this if condition checks if the array is already sorted then return none and merge process is ended
        return;
    cout<<"value of q:"<<q<<endl; // this print statement is just to check if it executes the following statements
    int n1=q-p+1;
    int n2= r-q;
    int a1[n1+1], a2[n2+1];// 2 new sub-arrays are created with n1 and n2 size
    for (int i=0;i<n1;i++)
        a1[i]=a[p+i];
    
    for (int i=0;i<n2;i++)
        a2[i]=a[q+1+i];
        
    int max = numeric_limits<int>::max();
   //sentinels are declared as the last element of the array
    a1[n1]=max;
    a2[n2]=max;
    
    int i=0,j=0;
    //merge function happens here in the for loop
    for (int k=p;k<=r;k++)
    {
        if (a1[i] <= a2[j])
        {
            a[k]= a1[i]; 
            i++;
        }
        else
        {
            a[k]= a2[j];
            j++;
        }
    }   
}

void mergesort(int a[],int p, int r)
{
    if (p<r)
    {
        int q=p+(r-p)/2;//this checks the overflow of q; r-p is divided by 2 then added with p
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r); 
    }
}

int main()

{
    int n=4;
    int a[4]={2,3,4,5};
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    mergesort(a,0,n-1);
    cout<<"Sorted array:"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
        
    }
}