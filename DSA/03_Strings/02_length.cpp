#include<iostream>
using namespace std;


int length(string str){

    int j = 0;
    while(str[j] != '\0'){
        j++;
    }
    return j;
}

int length(char str[]){

    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}





int main()
{
    char arrStr[] = {'D','h','r'};
    cout<<length(arrStr)<<endl;


    string mystr = "Dhruv";
    cout<<length(mystr)<<endl;

    
    return 0;
}