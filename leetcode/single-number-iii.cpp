// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>

using namespace std;

// Compiled from 
// Leetcode's Approach 2: Two bitmasks 
// AND 
// https://leetcode.com/problems/single-number-iii/solutions/366935/single-number-iii/comments/627501
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (const int& num: nums) {
            bitmask ^= num;
        }
        int x = 0;
        for (const int& num: nums) {
            if (num > (num ^ bitmask)) {
                x ^= num;
            }
        }
        return {x, x ^ bitmask};
    }
};
