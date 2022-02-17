//Vanshika Jain
//nuid is 002194103
//ProcedureX is renamed as dofn
#include<iostream>
using namespace std;

void dofn(int a[], int n)
{
    for (int i=0; i<n-1;i++)
    {
        for(int j=n;j>i;j--)//bubble sorting using last index instead of adjacent idx
        {
            if (a[j]<a[j-1])// if last element is less than previous then swap
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}

int main()
{
    int n=5;
    int a[5]={3,4,2,5,1};//input
    
    dofn(a, n-1);//function call with array a and last index n-1
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl; //display sorted array
    }
}