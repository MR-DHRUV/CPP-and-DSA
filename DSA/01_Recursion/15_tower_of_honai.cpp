#include <iostream>
using namespace std;

void TOH(int n, int from, int inter, int to)
{
    if(n>0){
    TOH(n-1,from,to,inter);
    cout<<"From "<<from<<" to "<<to<<endl;
    TOH(n-1,inter,from,to);
    }
}

int main()
{
    TOH(3,1,2,3);
    return 0;
}