#include <stdio.h>

int main()
{
    // all wil give 4 output as size of int = 4, size of pointer = 4
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(int **));

    void *pVoid; // void pointer, can point to any type of data
    pVoid = (void *)0; // setting it to null
    printf("%lu", sizeof(pVoid)); // again 4 as its a pointer only

    int _ = 3;
    
    // octal number
    int c = 050; // is octal number 


    return 0;
}