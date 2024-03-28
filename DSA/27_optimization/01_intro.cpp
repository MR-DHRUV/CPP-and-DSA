#include <bits/stdc++.h>
using namespace std;

// detail: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

/*
    O2: default optimization

    O3:
    This is the first non-trivial optimization option. It can make your code slower sometimes (due to the large size of generated code), but it is not very frequent in competitive programming. Some of the things it does are:
    Auto-vectorize the code if the mentioned architectures allow it. This can make your code much faster by using SIMD (single instruction, multiple data) which kinda parallelizes your code on an instruction level. More info below.
    Function inlining — inlines functions aggressively if possible (and no, marking functions as inline doesn't inline functions, nor does it give hints to the compiler)

    Ofast: It turns on all optimizations that O3 offers, along with some other optimizations,some of which might not be standards compliant. For instance, it turns on the fast-math optimization, which assumes floating-point arithmetic is associative (among other things), and under this assumption, it is not unexpected to see your floating-point error analysis go to waste.

    unroll-loops: Enables aggressive loop unrolling, which reduces the number of branches and optimizes parallel computation, but might increase code size too much and lead to instruction cache misses.

    strict-overflow: Enables some optimizations that take advantage of the fact that signed integer overflow is undefined behavior.
*/

/*
GCC Target

    popcnt: CPUs that support the popcnt instruction can theoretically compile __builtin_popcount into one instruction, which is much faster than usual implementations of this function.
    popcnt, lzcnt — These optimize the popcount (__builtin_popcount family) and count leading zeros (__builtin_clz family) operations respectively.

    avx and avx2: These are instruction sets that provide 8, 16 and 32 byte vector instructions (i.e., you can do some kinds of operations on pairs of 8 aligned integers at the same time). Prefer using avx2 since it's newer. fma is not so widely used, since avx and sse make up for most of it already.

    abm, bmi, bmi2: These are bit manipulation instruction sets (note that bmi is not a subset of bmi2). They provide even more bitwise operations like ctz, blsi, and pdep.

    // DOES MOST OF THE THINGS
    #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
*/

/*
    #pragma GCC ivdep: This pragma forces the compiler to vectorize a loop if the loop was not vectorized due to possible aliasing. This means that the compiler wasn't able to prove that vectorizing is safe due to data dependency, but you can, due to knowledge of the problem at hand, show that this case will never happen. This results in undefined behaviour if you're not careful enough about there not being a dependency across loop iterations. Think of this having a similar idea behind it as pointer restrict in C99.
*/

// Fast IO
// Disable sync with C i/o
static int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

#pragma GCC optimize("O3,unroll-loops")
// OR
#pragma GCC optimize("Ofast")
// With
#pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{
  
  
    return 0;
}