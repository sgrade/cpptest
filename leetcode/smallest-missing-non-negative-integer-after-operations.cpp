// 2598. Smallest Missing Non-negative Integer After Operations
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/

#include <vector>

using std::vector;


// Based on Editorial's Smallest Missing Non-negative Integer After Operations
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mod_counts(value);
        for (const int num: nums) {
            int v = (num % value + value) % value;  // The double modulo ensures negative numbers are handled correctly
            ++mod_counts[v];
        }
        int mex = 0;
        while (mod_counts[mex % value] > 0) {
            --mod_counts[mex % value];
            ++mex;
        }
        return mex;
    }
};
