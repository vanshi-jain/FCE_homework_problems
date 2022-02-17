//Vanshika Jain
//NUID is 002194103

#include <iostream>
using namespace std;

struct Student
{// structure declared with two variables
    string Name;
    int Grade;
};
//swapping integer and string functions using reference variables- under partition function
void swapint(int& a, int& b)
{
    int t=a;
    a=b;
    b=t; 
}
void swapstr(string& a, string& b)
{
    string t=a;
    a=b;
    b=t;  
}
    
// function to decide pivot index for quicksort
int partition(Student stud[],int s,int e)
{
    int pivot=stud[e].Grade;
    int pidx=s;
    for(int i=s;i<e;i++)
    {
        if (stud[i].Grade >= pivot) //for descending order check if grade is greater than pivot value
        {
            // if its true then swap the grades and names with current values in the array of structures
            swapint(stud[i].Grade,stud[pidx].Grade);
            swapstr(stud[i].Name,stud[pidx].Name);
            pidx++; // increment the pivot index to move forward in the array while swapping it next time
        }
    }
    //pivot value is swapped with the curent position where the iteration stops to get left and right arrays with pivot in between them
    swapint(stud[e].Grade,stud[pidx].Grade);
    swapstr(stud[e].Name,stud[pidx].Name);
    return pidx;
}
// quicksort function declaration with student array, starting index and ending index
void quicksort(Student stud[], int s, int e)
{
    if(s<e) // this is to check if starting point has not reached the last index
    {
        int p=partition(stud,s,e);
        quicksort(stud, s, p-1); //left sub-array to the pivot
        quicksort(stud,p+1,e); // right sub-array to the pivot
    }// this is a recursive function with different pivot values, starting and ending index
}

//function to sort in descending order of the grades
void desc_grade(Student stud[], int l)
{
    cout<<"List before sorting:"<<endl;
    for (int i=0;i<l;i++)
    {
       cout<<stud[i].Name<<" "<<stud[i].Grade<<endl;
    }
    quicksort(stud,0,l-1); //l-1 indices since indexing starts from 0
    cout<<"List after sorting:"<<endl;

    for (int i=0;i<l;i++)
    {
       cout<<stud[i].Name<<" "<<stud[i].Grade<<endl;
    }
}
//function to find Average and median of the grades
void avg_med(Student stud[], int l)
{
    float s=0;
    for (int i=0;i<l;i++)
    {
        s+=stud[i].Grade;
    }
    s=s/l;
    //sum of all the grades divided by the size of the array
    cout<<"Average of all the grades is: "<<s<<endl;
    
    //median is calculated for both even and odd sizes of array
    float med;
    if (l%2!=0) //odd
    {
        med=stud[l/2].Grade;
    }
    else //even
    {
        med=(stud[l/2].Grade + stud[(l/2)-1].Grade)/2;
    }
    cout<<"Median of all the grades is: "<<med<<endl;
}

// function to find maximum score- the first person in the sorted array
void max_grade(Student stud[])
{
    cout<<"Maximum Grade is scored by "<<stud[0].Name<<" - "<<stud[0].Grade<<endl;
}

// function to find minimum score- the last(l-1) person in the sorted array
void min_grade(Student stud[],int l)
{
    cout<<"Minimum Grade is scored by "<<stud[l-1].Name<<" - "<<stud[l-1].Grade<<endl;
}

//main function
int main()
{
    int size;
    cout<<"Enter the size of the class(number of students): "<<endl;
    cin>>size;
    Student* stud = new Student[size]; 
    //dynamic array created using new pointer array with length equal to size
    cout<<"Enter the student Name and Grade (between 0 and 100):"<<endl;
    for (int i=0; i<size; i++)
    {
        cout<<"Student "<<i+1<<endl;
        cin>>stud[i].Name>>stud[i].Grade;
        
        //to check if the grade satisfies the criterion between 0 and 100; if not go back one step and ask the user again
        if (stud[i].Grade <0 or stud[i].Grade>100)
        {
            cout<<"Valid grade is between 0 and 100. Type again..."<<endl;
            i=i-1;
        }
    }
    //all functions are called in the output format
    desc_grade(stud,size);
    avg_med(stud,size);
    max_grade(stud);
    min_grade(stud,size);

    delete[] stud;// important to delete the dynamic memory created by new to deallocate the memory address
    
}
