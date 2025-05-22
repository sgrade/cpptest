// 3362. Zero Array Transformation III
// https://leetcode.com/problems/zero-array-transformation-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Greedy + Priority Queue
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int ops = 0, n = nums.size(), q = queries.size();
        vector<int> deltas(n + 1);
        for (int i = 0, j = 0; i < n; ++i) {
            ops += deltas[i];
            while (j < q && queries[j][0] == i) {
                pq.emplace(queries[j][1]);
                ++j;
            }
            while (ops < nums[i] && !pq.empty() && pq.top() >= i) {
                ++ops;
                --deltas[pq.top() + 1];
                pq.pop();
            }
            if (ops < nums[i])
                return -1;
        }
        return pq.size();
    }
};
