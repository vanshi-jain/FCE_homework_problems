//Vanshika Jain
//NUID is 002194103
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream> //libraries added for file operations
#include<stdexcept>

using namespace std;

//global variables act as counters for shifting and comparison
int moves;
int comps;
//swapping function used in all algorithms 
void swap(int& x, int&y)
{
  	int temp =x;
	x=y;
	y=temp;
	moves=moves+3;// moves are incremented by 3 because the shifting takes place thrice
}
// array generator for 3 cases- best, average and worst
void generate_arrays(int BST[], int AVG[],int WST[])
{
    for (int i=0; i<1000; i++)
    {
        BST[i]=(i+1)*10; //best case arrays are sorted in ascending order
    }
    
    srand (time(NULL));// for randomness each time the program is run

    for (int j=0; j<1000; j++)
    {
        int x = rand()% 100000 + 1;
        AVG[j]= x; //average case arrays are random numbers
    }
    
    int w=1000;
    for (int k=0; k <1000; k++)
    {
        WST[k]= w * 10; //worst case arrays are in descending order
        w-=1;
    }
}
//function to check the array is sorted in ascending order
int check_sorted_array (int array[])
{
	for(int i=0;i<999;i++)
	{
		if(array[i]<=array[i+1])
		{
			continue;
		}
		else
		{
			return 0; // even if one element is not lesser than the next element then return 0
		}
	}
	cout<<"Array is sorted!"<<endl;
	return 1;
}
//iterative insertion sort algorithm
void IIS(int a[])
{
	if (check_sorted_array(a))
	{
	    cout<<"Array is already sorted"<<endl; //to identify if it is a best case
	}
	int key,j;
	bool loop=false; //flag to identify loop or no loop
	//sort elements starting from index 1 
	for (int i=1; i<1000; i++)
    {
	//insert last element at its correct position in the sorted array
	    key = a[i];
	    j = i-1;
	    //comps+=1;// this comparison is for j from 0 to 999 for each increment in i
	    
	    while (j >= 0 && a[j] > key)
	    {
	        comps++; //this comparison is for the above condition in while loop
		    a[j+1] = a[j];
		    moves+=1;
		    j--;
		    loop=true;
	    }
	    a[j+1] = key;
	    if(!loop)   comps++;
    }
}
// heap sort algorithm
//max heapify--> sub-function of building a heap
void max_heapify(int a[], int root, int size) 
{ 
    int largest = root; 
    int l = 2 * root + 1; // left child 
    int r = 2 * root + 2; // right child

    // if left child is larger than the root 
    comps=comps+1;
    if (l < size && a[l] > a[root]) largest = l;
         
    // If right child is larger than the current largest  
    comps=comps+1;
    if (r < size && a[r] > a[largest]) largest = r; 
  
    // If largest is not root 
    if (largest != root) 
    { 
        swap(a[largest],a[root]);
        //recursively call max-heapify from the affected sub-tree 
        max_heapify(a,largest,size); 
    } 
} 
//heap sort function
void HS(int a[])
{
	if(check_sorted_array(a)) //check to see if the array is already sorted for best case
	{
		cout<<"Array is sorted already"<<endl; 
	}
    int size=1000;
	for(int i=((size/2)-1); i>=0; i--)
		max_heapify(a,i,size); //max-heap for building a heap structure
		
	//One by one extract an element from heap 
    for (int i = 999; i > 0; i--) 
    { 
        //Move current root to end 
        swap(a[0],a[i]);
		//call max heapify on the reduced heap 
		max_heapify(a,0,i); 
    } 
}
//quicksort algorithm
int partition (int a[], int p, int r) 
{ 
    int pivot = a[r]; //start value as the pivot value
    int pidx = p;  //index of smaller element 

    for (int i = p; i < r; i++) 
    { 
        // If current element is smaller than or equal to pivot value
        comps=comps+1;
        if (a[i] <= pivot) //ascending order 
        { 
            swap(a[i],a[pidx]);
            pidx++;  //increment index of pivot 
        }
    }
    swap(a[r],a[pidx]);
    return pidx;
}  
//quicksort recursive--> sub-function that implements QuickSort operations
void QSR(int a[], int p, int r) 
{ 
	int q=0;
    if (p < r) 
    { 
        //q is partitioning index 
        q = partition(a, p, r); 
  		//recursively call QSR operation
        QSR(a, p, q-1); 
        QSR(a, q+1, r); 
    } 
} 
//main function to implement QuickSort
void quick_sort(int a[])
{
	int p=0;//starting index
	int r=1000-1; //ending index
	if(check_sorted_array(a)) //check to see of the array is already sorted for best case
		cout<<"Array is sorted already"<<endl; 	
	QSR(a, p, r);	
}
//array copy for all three cases and for each algorithm
void arrayCopy(int BST[], int AVG[],int WST[],int tBST[],int tAVG[],int tWST[] )
{
    for (int i =0; i<1000;i++)
    {
        tBST[i]=BST[i];
        tAVG[i]=AVG[i];
        tWST[i]=WST[i];
    }

}
//main function to implement all the above functions
int main()
{
    int n=1000;
    int BSTI[n],AVGI[n], WSTI[n];
    int BSTH[n],AVGH[n], WSTH[n];
    int BSTQ[n],AVGQ[n], WSTQ[n];
    //testing arrays for best average and worst case
    int tBST[1000], tAVG[1000],tWST[1000];
    //generating arrays for each algorithm
    generate_arrays(BSTI,AVGI,WSTI);
    generate_arrays(BSTH,AVGH,WSTH);
    generate_arrays(BSTQ,AVGQ,WSTQ); 
    //copying arrays for Insertion sort
    arrayCopy(BSTI,AVGI,WSTI,tBST,tAVG,tWST);  
    //creating file object
    ofstream outfile;
    outfile.open("data.txt");
    //best case
    //initialize both moves and comps to zero before every call
    moves=0;
    comps=0;
    cout<<"Insertion sort best case"<<endl;
    IIS(tBST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
    outfile<<"Insertion Sort:"<<endl ;
	outfile<<"Best Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//average case 
	moves=0;
    comps=0;
    cout<<"Insertion sort average case"<<endl;
    IIS(tAVG);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"Avg Case scenario:\t\t";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//worst case
	moves=0;
    comps=0;
    cout<<"Insertion sort worst case"<<endl;
    IIS(tWST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"Worst Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<"\n"; 

	//verification of arrays--> sorted or not
    cout<<check_sorted_array(tBST)<<endl;
    cout<<check_sorted_array(tAVG)<<endl;
    cout<<check_sorted_array(tWST)<<endl;
/////////////////////////////////////////////////////////////
	//copying arrays for Heap sort  
    arrayCopy(BSTH,AVGH,WSTH,tBST,tAVG,tWST);  
	//best case 
	moves=0;
    comps=0;
    cout<<"Insertion sort best case"<<endl;
    HS(tBST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
    outfile<<"Heap Sort:"<<endl ;
	outfile<<"Best Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//average case
	moves=0;
    comps=0;
    cout<<"Heap sort avg case"<<endl;
    HS(tAVG);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"Avg Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//worst case
	moves=0;
    comps=0;
    cout<<"Heap sort worst case"<<endl;
    HS(tWST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"Worst Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<"\n"; 
	
    //verification of arrays--> sorted or not
    cout<<check_sorted_array(tBST)<<endl;
    cout<<check_sorted_array(tAVG)<<endl;
    cout<<check_sorted_array(tWST)<<endl;
//////////////////////////////////////////////////////
	//copying arrays for Quick sort  
    arrayCopy(BSTQ,AVGQ,WSTQ,tBST,tAVG, tWST);  
	//best case
	moves=0;
    comps=0;
    
    cout<<"quick sort best case"<<endl;
    quick_sort(tBST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
    outfile<<"Quick Sort:"<<endl ;
	outfile<<"Best Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//average case
	moves=0;
    comps=0;
    cout<<"quick sort avg case"<<endl;
    quick_sort(tAVG);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"Avg Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
	//worst case
	moves=0;
    comps=0;
    cout<<"quick sort worst case"<<endl;
    quick_sort(tWST);
    if (outfile.fail())
    {
        cerr<<"Error: Could not open file"<<endl;
        exit(1);
    }
	outfile<<"worst Case scenario:\t\t ";
	outfile<<"Values of moves: "<< moves<<"\t";
	outfile<<"Values of comps: "<<comps<<endl; 
    
    outfile.close();
    	
    //verification of arrays-->  sorted or not
    cout<<check_sorted_array(tBST)<<endl;
    cout<<check_sorted_array(tAVG)<<endl;
    cout<<check_sorted_array(tWST)<<endl;

    return 0;
}
