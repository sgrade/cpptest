// 1508. Range Sum of Sorted Subarray Sums
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Priority Queue
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i)
            pq.emplace(nums[i], i);
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= right; ++i) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (i >= left)
                ans = (ans + num) % MOD;
            if (idx < n - 1)
                pq.emplace (num + nums[++idx], idx);
        }
        return ans;
    }
};
