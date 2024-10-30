// 1671. Minimum Number of Removals to Make Mountain Array
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: LIS Using Dynamic Programming
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        vector<int> lis(n, 1); // Longest strictly Increasing subsequence
        vector<int> lds(n, 1); // Longest strictly Decreasing subsequence
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (lis[i] > 1 && lds[i] > 1)
                ans = min(ans, n - lis[i] - lds[i] + 1);
        }
        return ans;
    }
};
