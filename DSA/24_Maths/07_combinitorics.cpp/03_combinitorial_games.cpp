#include <bits/stdc++.h>
using namespace std;



int main()
{
    // these are 2 person games with a win or loose outcome
    // where both play optimally 
    // N and P / W and L / win and loose positions

    // Eg: Game of NIM, 80% of the questions are converted to this only in game theory
    // The Nim Game is a combinatorial game that involves a number of piles of coins and two players playing the game. In each turn, one player chooses a pile and removes any number (> 0) of coins from the pile. The person who cannot make a move loses in the end or the one who removes the last coin wins.

    // Obseravtion
    // For a two pile game (n,n) is always a loosing state if turn is mine

    // For a three pile game 
    // (1,1,1) w
    // (0,1,1) l
    // (y,x,x) W as I can convert this to (0,x,x) for other player, so I always win
    
    // To generalize, I have to try to convert any position to loosing position for other player in my move

    // Nim-Sum
    // it the sum of two non negitive numbers without carry in binary
    // a = 12 = 1100 
    // b = 09 = 1001 
    // sum    = 0101
    // basically its a xor b

    // Now for a N pile game 
    // (x1,x2,...,xn)
    // nim sum = x1^x2^..^xn

    // this is how we will represent a nim game as a nim sum
    // Theorem : A state (x1,x2,x3...,xn) is a loosing position if nimsum = 0 and move is mine

    // (1,3,5,7)
    /*
        0 0 1  1
        0 1 1  3
        1 0 1  5
        1 1 1  7
        0 0 0  nim sum  

        why so?

        for every corresponding move we have another move to cancel it out so second player wins
        if this xor is not zero, then there exit some moves which dont have a corresponding move for second player
    */

   // winning stratagy is to fininsh every move with nimsum = 0  
   // Theorem : it is always possible to make nimsum 0 on your move if it was'nt 0 already

   // say nimsum = 10110 = x1^x2^x3^x4
   // now inorder to make nimsum 0 and say msb is from x4, so we will remove (x1^x2^x3) coins from x4 to make total ninsum = 0

   // 





    
    return 0;
}