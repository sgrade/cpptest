// 2369. Check if There is a Valid Partition For The Array
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memo.resize(n + 1, -1);
        memo[0] = 1;
        return PrefixIsValid(nums, n - 1);
    }

private:
    int n;
    vector<int> memo;
    bool PrefixIsValid (vector<int>& nums, int i) {
        if (memo[i + 1] != -1) 
            return memo[i + 1];
        
        bool ans = false;

        if (i > 0 && nums[i] == nums[i - 1])
            ans |= PrefixIsValid(nums, i - 2);
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
            ans |= PrefixIsValid(nums, i - 3);
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
            ans |= PrefixIsValid(nums, i - 3);
        
        memo[i + 1] = ans;
        return ans;
    }
};
