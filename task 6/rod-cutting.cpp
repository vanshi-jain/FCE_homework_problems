//vanshika jain
//nuid is 002194103

#include <stdio.h>
#include <math.h>
#include <limits.h> 
#include <sys/time.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

//Function for returning maximum value
int maximum(int x, int y) 
{
    if (x > y)  return x;
    return y;
} 

//Function for calling recursive implementation for the rod cutting problem
int rodCuttingR(int cost[], int n) 
{
    int max = INT_MIN;//define maximum value as the least minimum integer
    if (n <= 0) return 0; // if length of the rod is less than or equal to zero then return zero    
    for (int i = 0; i < n; i++) //else find the maximum cost of this rod cutting recursively with one less size of the array
        max = maximum(max, cost[i] + rodCuttingR(cost, n-i-1)); 
    return max; 
}

// Function for calling dynamic implementation for the rod cutting problem
int rodCuttingD(int cost[], int n) 
{
    int store[n+1]; //initialize an array to store maximum value already computed
    store[0] = 0; //define the first value as zero 
    for (int i = 1; i<=n; i++) 
    { 
        int max = INT_MIN; //to re-initialize the max value after every iteration
        for (int j = 0; j < i; j++)    //find the maximum cost of this rod between array values j=0 to i and maximum value stored previously
            max = maximum(max, cost[j] + store[i-j-1]); 
        store[i] = max; 
    } 
   return store[n]; 
} 
   
// Driver Function for performing different tasks as mentioned in the Problem-2
int main() 
{ 
    int rod_sizes[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; // rod size array declaration and initialization
    int max_cost=0, max_cost2=0; // variable for storing calculated max cost
    cout << "Rod-cutting problem in two approaches-" << endl;
    cout << "--------dynamic implementation-----------" << endl;
    
    //calculating the prices of each rod according to the given formula
    int len=sizeof(rod_sizes)/sizeof(rod_sizes[0]); //total number of available rod sizes for this problem

    //formula to calculate the cost price for each rod for each length
    for (int i = 0; i <len ; i++)
    {
        int size = rod_sizes[i];
        int costs[size]; //price array to store all the prices
        int idx = 0; //initialize index as 0 to store the prices in the costs array

        for (int l = 1; l <= size; l++) // minimum length of the rod must be 1
        {

            if (l == 1) //when the length is 1 cost is 2
            {
                costs[idx] = 2.0;
                idx++;
            }

            if ( l > 1 && l < size) //when the length is between 1 and the size of the rod, cost is as follows
            {
                costs[idx] = floor (l * 2.5);
                idx++;
            }

            if (l == size) //when the length is equal to the size of the rod, cost is as follows
            {
                costs[idx] = (l * 2.5 - 1);
            }
        }

        //dynamic implementation for the rod cutting problem for calculating maximum cost and time taken
        auto start = chrono::high_resolution_clock::now();
        max_cost = rodCuttingD(costs, size); //calculating maximum cost for current rod and all the prices for all the lenghts
        auto elapsed = chrono::high_resolution_clock::now() - start;
        long long microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();

        printf("The max revenue for size  = %d is %d\n", size, max_cost);
        printf("Time taken is = %lld microseconds\n", microseconds);
    }

    cout << "--------recursive implementation----------" << endl;
     for (int i = 0; i <len ; i++)
    {
        int size = rod_sizes[i];
        int costs[size]; //price array to store all the prices
        int idx = 0; //initialize index as 0 to store the prices in the costs array

        for (int l = 1; l <= size; l++) // minimum length of the rod must be 1
        {

            if (l == 1) //when the length is 1 cost is 2
            {
                costs[idx] = 2.0;
                idx++;
            }

            if ( l > 1 && l < size) //when the length is between 1 and the size of the rod, cost is as follows
            {
                costs[idx] = floor (l * 2.5);
                idx++;
            }

            if (l == size) //when the length is equal to the size of the rod, cost is as follows
            {
                costs[idx] = (l * 2.5 - 1);
            }
        }

        //recursive implementation for the rod cutting problem for calculating maximum cost and time taken
        auto start2 = chrono::high_resolution_clock::now();
        max_cost2 = rodCuttingR(costs, size);
        auto elapsed2 = chrono::high_resolution_clock::now() - start2;
        long long microseconds2 = chrono::duration_cast<chrono::microseconds>(elapsed2).count();

        printf("The max revenue for size  = %d is %d\n", size, max_cost2);
        printf("Time taken is = %lld microseconds\n", microseconds2);
    
    }
    return 0; 
} 