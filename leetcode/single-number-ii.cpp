// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Bitwise Operators : NOT, AND and XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for (const int &num: nums) {
            // change seen_once only if seen_twice is unchanged
            seen_once = ~seen_twice & (seen_once ^ num);
            // change seen_twice only if seen_once is unchanged
            seen_twice = ~seen_once & (seen_twice ^ num);
        }
        return seen_once;
    }
};
