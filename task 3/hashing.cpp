
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <string>
using namespace std;

int randomGenerator(int lowerLimit, int upperLimit)
{
	int randomNumber = 0;
	randomNumber = (rand() % (upperLimit-lowerLimit + 1)) + lowerLimit;
	return randomNumber;
}

void birthdayGenerator(int birthday[])
{

	for (int i=0;i<1000;i++)
	{
		birthday[i]= (randomGenerator(1,12) * 10000) + (randomGenerator(1,28) * 100) + (randomGenerator(0,4)); 
	}	
}

void hashtTable(int birthday[],int m)
{
    int coll[m];
    for ( int i=0;i<m;i++)
    {
        coll[i]=0;
    }
    
    for(int j=0;j<1000;j++)
    {
        coll[birthday[j]% m]++;
    }
    int minimum=coll[0];
	int maximum=coll[0];
	int mean=0;
	int variance=0;
	int sum=0;
	for (int i=0;i<m;i++)
	{
		if (minimum>coll[i])
		{
			minimum=coll[i];
		}

		if (maximum<coll[i])
		{
			maximum=coll[i];
		}
		sum=sum+coll[i];
	}
	mean=sum/m;
	for (int i=0;i<m;i++)
	{
		variance = variance + ((coll[i] - mean) * (coll[i] - mean));
	}

	variance=variance/m;

	
	cout << "Hash table with size --> " << m << endl;
	cout << "Minimum --> " << minimum << endl;
	cout << "Maximum --> " << maximum << endl;
	cout << "Mean --> " << mean << endl;
	cout << "Variance --> " << variance << endl;
	cout << "Maximum Number of collisions --> " << maximum-1 << endl;
}

int main()
{
	int birthday[1000];
	int m1=97;
	int m2=98;
	int m3=100;
	int m4=101;
	
	birthdayGenerator(birthday);

	hashtTable(birthday,m1);
	hashtTable(birthday,m2);
	hashtTable(birthday,m3);
	hashtTable(birthday,m4);


	return 0;
}