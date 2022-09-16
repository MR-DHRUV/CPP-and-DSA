#include<iostream>
using namespace std;

void update(int n)
{
    n++;
}

//&n is a refrance variable
void update2(int &n)
{
    n++;
}


int main()
{
    int i = 5;
    // refrence varible points to same block of memory, its like 1 child having 2 names
    // no extra memory is uses or no copy of i is made 
    //creating a refrence variable
    int &j = i;

     
    cout<<j<<endl;
    j++; // equivalent to i++;

    //same value aaygi , j aur i ek hi hain
    cout<<i<<endl;
    cout<<j<<endl;


    // why we need refrence variables
    int n = 5;
    int &ref = n; 
    cout<<n<<endl;
    update(n);
    // no change in value
    cout<<n<<endl;

    update2(n);
    // change in value as functions takes refrence of n , copy nahi bani thus pass by value ni hua , pass by refrence hua haii, same as passing pointer  
    cout<<n<<endl;

    


    return 0;
}