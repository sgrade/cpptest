// 862. Shortest Subarray with Sum at Least K
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Priority Queue
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        int ans = numeric_limits<int>::max();
        long long sum = 0;

        // <prefix_sum, index>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefix_sums;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum >= k)
                ans = min(ans, i + 1);
            while (!prefix_sums.empty() && sum - prefix_sums.top().first >= k) {
                ans = min(ans, i - prefix_sums.top().second);
                prefix_sums.pop();
            }
            prefix_sums.emplace(sum, i);
        }
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
