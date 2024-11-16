// 3254. Find the Power of K-Size Subarrays I
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> ans;
        queue<int> q;
        int i = 0;
        while (i < nums.size()) {
            if (!q.empty() && nums[i] - 1 != q.back())
                q = queue<int>();
            q.emplace(nums[i]);
            if (i >= k - 1) {
                int current_ans = q.size() >= k ? q.back() : -1;
                ans.emplace_back(current_ans);
            }
            ++i;
        }
        return ans;
    }
};
