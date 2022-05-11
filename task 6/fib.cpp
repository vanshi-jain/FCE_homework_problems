//Vanshika Jain
//nuid is 002194103

#include <iostream>
#include <stdio.h>
#include <time.h> //to compute the total time taken 

using namespace std;
int A[50]; //global array declaration for Dynamic programming

//function for Dynamic programming approach
int FibonacciD(int n)
{
    if (n<=1)   return n; //for n=0 and n=1, the Fibonacci sequence is n itself
    if (A[n] !=-1)    return A[n]; //when array[index] has some value other than -1 which is useful to store that means its visited
    else    
    {
        A[n]=FibonacciD(n-1) + FibonacciD(n-2); //else calculate the Fibonacci and store it 
        return A[n];
    }
}

//function for recursive approach
int FibonacciR(int n)
{
    if (n<=1)   return n;
    return FibonacciR(n-1) + FibonacciR(n-2); //compute the Fibonacci of each element starting from n till it reaches 1

}
//given main function
int main()
{
    int n; //The user inputs this number to calculate its Fibonacci sequence
    cout << "n = "; //5,10,20,30,40
    cin >> n;
    clock_t start,start2; //time variables to compute time taken for processing
    // initialize all elements in array A to an invalid Fibonacci value
    for (int i = 0; i <= n; i++)  
        A[i] = -1;
   
    //Find Fibonacci sequence n using the Dynamic programming function
    start= clock();
    printf("FibonacciD(%d) = %d\n",n,FibonacciD(n-1));
    cout<<"Time taken by Dynamic programming: "<<(float) (clock()-start)/ CLOCKS_PER_SEC <<" seconds"<<endl;
    cout<<endl;
    
    //Find Fibonacci sequence n using the recursive only function
    start2=clock();
    printf("FibonacciR(%d) = %d\n",n,FibonacciR(n-1));
    cout<<"Time taken by Recursive approach: "<<(float)(clock()-start2)/ CLOCKS_PER_SEC <<" seconds"<<endl;
}