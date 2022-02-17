//Vanshika Jain
//Nuid is 002194103

#include <iostream>
//#include<cmath> to include clock
using namespace std;

int F1(int);
int F2(int);

int main()
{
    unsigned int n;
    //clock_t start,end,start2,end2; //just to test the time taken by two functions
    cout<<"enter n between 1 and 10:"<<endl;
    cin>>n;
    //start=clock();
    int one=F1(n);
    //end=clock();
    
    //start2=clock();
    int two=F2(n);
    //end2=clock();
    
    cout<<one<<endl;//value computed by F1
    //double d=double(end -start)/ double(CLOCKS_PER_SEC);
    //cout<<"time taken by F1: "<< d<<endl;
    
    cout<<two<<endl;//value computed by F2
    //double d2=double(end2 -start2)/ double(CLOCKS_PER_SEC);
    //cout<<"time taken by F2: "<<d2<<endl;
    return 0;
}

int F1(int n)
{
    //cout<<"This is F1"<<endl;
    if (n == 0) return 1;
    return F1(n- 1) + F1(n- 1);//recursive call
}

int F2(int n)
{
    //cout<<"This is F2"<<endl;
    if (n == 0) return 1;
    if (n % 2 == 0) {//checks if even or odd
        int result = F2(n / 2);//F2 is called logn times
        return result * result;
    }
    else
        return 2 * F2(n -1);//recursive call with n-1 times
}
