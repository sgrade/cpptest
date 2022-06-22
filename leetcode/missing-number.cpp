// 268. Missing Number
// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>

using namespace std;


/*
https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation
First, we need to understand the properties of XOR: firstly, XOR'ing a number by itself results in 0. 
So if we have 1 ^ 1, this will equal 0. 
Secondly, XOR is commutative and associative - 
what this means is we can re-order our XOR operations in any way we want and it will result in the same value we would have if we didn't. 
Finally, a number XOR'd by 0 will result in the same number unchanged. 
So, essentially, by XOR'ing all the numbers from 0 to n, and all the numbers in the array, 
we will end up XOR'ing 2 of every number except for the missing one. 
As we know, it doesn't matter which order we XOR these numbers in - as long as we XOR 2 of the same number, it will result in 0. 
So eventually we will get 0 ^ the missing number, which, due to the third property I mentioned, will simply equal the missing number. 
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};
