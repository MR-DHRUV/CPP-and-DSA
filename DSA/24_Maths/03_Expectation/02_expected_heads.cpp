#include <bits/stdc++.h>
using namespace std;

// N conscutive heads
int exNhead(int n)
{
    // how we will build ans 
    // T
    // H T
    // H H T
    // H H H T
    // till all head 

    // ans will be as follows
    // x = (x+1) *1/2 + (x+2)*1/2*1/2 + (x+3)*1/2*1/2*1/2

    // jitne coins h unti baat1/2 hoga as 
    // probability of H H T is 1/8

    // x = x(1/2 + ... 1/2^N) + (1/2 + 2/4 + 3/8 + ... N/2^N)
    // x = 2^N+1 - 2

}

int main()
{
    // A fair coin is thrown N times so what is the expected no of heads
    int N = 1000;

    // for any coin ci we can have 1->head, 0->tail
    // P(ci) = 1/2
    // E[h] = 1*1/2 + 0*1/2 = 1/2

    double eh = 0.5;

    long double ans = eh * 1ll * N;


    // What is the expected number of coin flips to get a head
    // we can get a head or tail 
    // say we need x throws
    // x = 1 p(head) + (x+1) p(tail)
    // if 1st baar me head aagye then we need 1 throw, but if tail agya toh i need x more throws and +1 as 1 is wasted by getting tail

    // x = 1X0.5 + (x+1)X0.5
    // 2x = x+2
    // x = 2

    // What is the expected number of coin flips to get 2 consicutive heads
    // x = 2 p(head head) + (x+2) p(head tail) + (x+1) p(tail)
    // 1st coin pr tail aagya toh kyu ucchalu 2nd coin 
    // x = 2*1/4 + (x+2)*1/4 + (x+1)*1/2
    // x = 6 

    // N conscutive heads
    cout<<exNhead(100)<<endl;
    

    return 0;
}