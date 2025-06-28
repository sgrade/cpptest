// 2099. Find Subsequence of Length K With the Largest Sum
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < k; ++i)
            pq.emplace(nums[i], i);
        for (int i = k; i < nums.size(); ++i) {
            if (pq.top().first < nums[i]) {
                pq.pop();
                pq.emplace(nums[i], i);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            pq2.emplace(idx, num);
        }

        vector<int> ans;
        while (!pq2.empty()) {
            auto [_, num] = pq2.top();
            pq2.pop();
            ans.emplace_back(num);
        }
        return ans;
    }
};
