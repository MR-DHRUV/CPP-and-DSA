#include<iostream>
using namespace std;

// tail recursion
int func(int n)
{
    if (n > 0)
    {
        cout<<n<<endl;
        return func(n - 1);
        // when recursive call is the last statement in a function then it is called tail recursion; 

        // return func(n - 1) + n; it is not a tail reccursive function as pahle func(n-1) evaluate hota then hi n ko add kara ja skta haii, so n is at tail        

    }

    return 0;
}

// conversion to loop

int funcLoop(int n)
{
    while(n>0){
        cout<<n<<endl;
        n--;
    }

    return 0;
}


int main()
{   
    func(3);

    return 0;
}


// time complexity of both is O(n) as same no calls are being made 


// space comlexity

// recursion stack me naye "n" banayga for each iteration 
// space complexity = O(n)


// loop ek hi n ko decrese kr rha haii, koi nayi copy ni ban rahi nayi iteration ke liye 
// so space complexity for loop = O(1) = constant 