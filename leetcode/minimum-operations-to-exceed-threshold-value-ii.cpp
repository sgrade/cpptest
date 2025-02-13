// 3066. Minimum Operations to Exceed Threshold Value II
// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
        int ans = 0;
        while (pq.top() < k) {
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            long z = min(x, y) * 2 + max(x, y);
            pq.emplace(z);
            ++ans;
        }
        return ans;
    }
};
