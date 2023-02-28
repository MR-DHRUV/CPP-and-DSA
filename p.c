load the prefix XORED array into trie
insert 0 first
get max xor of trie elements and current element, then insert it

Why ?
ans will be either from
a continues subarray starting from 0
a single element
or a continues subarray starting from somewhere in between

for a contunues subrray starting from 0
eg : 110011 is our ans , when we cross check it for max xor with our trie, 0 will return same 110011
as a^0 = a

for a single element
arr : 3 11 15
prefix arr : 3 8 7

when we'll look for 7 we'll have 3,8,0 in trie
wen we'll xor 7 with 8, it will again set the bits to make 15
its like removing some portion from a pirticular sub array and same will be followed for a continues subarray starting from somewhere in between where we will remove some part from it
