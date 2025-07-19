// 1005. Maximize Sum Of Array After K Negations
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        priority_queue<int, vector<int>, greater<int>> pq (nums.begin(), nums.end());
        while (k--) {
            int cur = pq.top();
            pq.pop();
            pq.emplace(-cur);
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
