#include <iostream>
using namespace std;



void funcA(int n){
    if(n>0){
        cout<<n<<endl;
        funcB(n-1);
    }
};

void funcB(int n){
    if(n>1){
        cout<<n<<endl;
        funcA(n/2);
    }
};



int main()
{
    /***
     
                   A
               /      \
              /        \
            B --------> C     

        a b  ko  bulata haii b c ko aur c a ko and cycle continues

    ***/

   funcA(20);




    return 0;
}