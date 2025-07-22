// 1695. Maximum Erasure Value
// https://leetcode.com/problems/maximum-erasure-value/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size(), ans = 0, left = 0;
        vector<int> prefix_sum(n + 1);
        unordered_map<int, int> indexes;
        for (int right = 0; right < n; ++right) {
            int current = nums[right];
            prefix_sum[right + 1] = prefix_sum[right] + current;
            if (indexes.find(current) != indexes.end())
                left = max(left, indexes[current] + 1);
            int current_ans = prefix_sum[right + 1] - prefix_sum[left];
            ans = max(ans, current_ans);
            indexes[current] = right;
        }
        return ans;
    }
};
