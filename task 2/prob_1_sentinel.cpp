//Vanshika Jain
//NUID is 002194103

#include<iostream>
#include<cstdlib> // random header file is added to generate random numbers in an array
#include<climits>
#include<limits> // limits header file is added to define a max int value
using namespace std;

void merge(int a[],int p, int q, int r)
{
    int n1=q-p+1;
    int n2= r-q;
    // two new sub-arrays are created with n1+1 and n2+1 as their size
    int a1[n1+1], a2[n2+1];

    for (int i=0;i<n1;i++)
        a1[i]=a[p+i]; // left sub-array
    
    for (int i=0;i<n2;i++)
        a2[i]=a[q+1+i]; // right sub-array
        
    int max = std::numeric_limits<int>::max(); //maximum int value-> 2^31-1 is added as the last value in both arrays
    a1[n1]=max;
    a2[n2]=max;
    //this is the sentinel value that helps in reducing the total number of operations while merging

    int i=0,j=0; 
    for (int k=p;k<=r;k++) // loop run from p to end of the array r
    {
        if (a1[i] <= a2[j]) // checks the lesser or equal to value in both sub arrays 
        {
            a[k]= a1[i]; //edits the original array with left sub-array values
            i++;
        }
        else
        {
            a[k]= a2[j];//edits the original array with right sub-array values
            j++;
        }
    }
}
// mergersort fucntion is called recursively until starting index is lesser than last index
void mergesort(int a[],int p, int r)
{
    if (p<r)
    {
        int q=p+(r-p)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r); //merge function is called after the array is cut down to the least possible sub-array
    }
}

int main()

{
    int n;
    cout<<"Enter n btw 1 and 51:";// n value between 1 and 51 is asked from the user as the size of the array
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        int x=0;
        x=(rand() % 100)+1;     // this is to create a randomly generated array with size n and numbers between 0 and 100
        a[i]=x;// array is filled with random numbers till size n
        cout<<a[i]<<endl; // display array before sorting
        
    }
    mergesort(a,0,n-1); //mergesort function is called with p=0, r=n-1(last index)
    cout<<"Sorted array:"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl; //display array after sorting
        
    }
}