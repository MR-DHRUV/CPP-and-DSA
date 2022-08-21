#include<iostream>
using namespace std;


// general reccursive function

/**
type func(params){

    if(base condition 1){   // Ascending Phase

    }
    if(base condition 2){

    }
    func(params)  // Descending phase

    return 
}
**/

// tracing tree of reccursive function



void func1(int n){
    if(n>0){
        cout<<n<<endl;
        func1(n-1); 
    }
}


int main()
{
    int x =3;
    func1(3);
    return 0;
}



/**
utilization of stack by the aobve program step by step 

------------------------------------------------------------------------

Heap
----------------------------------------------------------------------------

func1(0) ->   0 n

func1(1) ->   1 n 

func1(2) ->   2 n

func1(3) ->   3 n
main     ->   3 x 

Stack (LIFO)
-----------------------------------------------------------------

func1
main

Code
------------------------------------------------------------------
**/

// total calls = 4 = n + 1  = no of activation records created

// memory consumed / space complexity => O(n)  


// time complexity 

// let time to process unit call  -> k
// total calls => n+1
// time taken => nk + k + k2        (k2 for main)

// time complexity => O(n) => order of 'n'


// reccurance relation to find time complexity



