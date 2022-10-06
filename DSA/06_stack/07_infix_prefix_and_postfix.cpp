#include<bits/stdc++.h>
using namespace std;



int main()
{
    // what is postfix , prefix and infix

    // infix : operand operator operand
    // eg : a + b

    // infix : operator operand operand
    // eg : +ab

    // infix : operand operand operator
    // eg : ab+

    // why we need prefix and postfix
    
    // this is the order in which these operations will be done 
    // in order to do these operations we have to scan whole expression and analize which one should be done
    // 8 + 3 * (9-6)/ 2^2 + 6/2
    //   6   5   1  3  2  7  4

    // to get these done in a single scan, we use prefix and postfix
    // 8 3 9 6 - 2^2 / * + 6 2 / +
                                                                                                            
    return 0;
} 