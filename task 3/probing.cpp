#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int h1(int key)
{
	int x=(key+5)*(key+5);
	x=x/16;
	x=x+key;
	x=x%11;
	return x;
}

int main()
{
	int key[]={43, 23, 1, 0, 15, 31, 4, 7, 11, 3, 5, 9};
	int size = sizeof(key)/sizeof(key[0]); 
	
	cout << "According to the given hash function " << endl;
	for (int i=0;i<size;i++)
	{
		int position=h1(key[i]);
		cout << "The position of the key value " << key[i] << " -->  " << position << endl;
	}
	
}