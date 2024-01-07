// 446. Arithmetic Slices II - Subsequence
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2 Dynamic Programming
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long, int>> memo(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - nums[j];
                int sum = 0;
                if (memo[j].find(diff) != memo[j].end())
                    sum = memo[j][diff];
                memo[i][diff] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};
