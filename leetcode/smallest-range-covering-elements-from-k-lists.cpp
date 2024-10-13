// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Priority Queue (Heap)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // <num, <list_idx, num_index>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int mx = numeric_limits<int>::min(), left = 0, right = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i][0], pair<int, int>{i, 0});
            mx = max(mx, nums[i][0]);
        }

        while (pq.size() == nums.size()) {
            auto [mn, indexes] = pq.top();
            pq.pop();
            auto& [list_idx, num_idx] = indexes;
            if (mx - mn < right - left) {
                left = mn;
                right = mx;
            }
            if (num_idx + 1 < nums[list_idx].size()) {
                int next_num = nums[list_idx][num_idx + 1];
                pq.emplace(next_num, pair<int, int>{list_idx, num_idx + 1});
                mx = max(mx, next_num);
            }
        }
        return {left, right};
    }
};
