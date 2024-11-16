// 3254. Find the Power of K-Size Subarrays I
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (k == 1) return nums;
        vector<int> ans;
        int cnt = 1, prev = nums[0], i = 1;
        while (i < nums.size()) {
            if (nums[i] - 1 != prev)
                cnt = 0;
            prev = nums[i];
            ++cnt;
            if (i >= k - 1) {
                int current_ans = cnt >= k ? prev : -1;
                ans.emplace_back(current_ans);
            }
            ++i;
        }
        return ans;
    }
};
