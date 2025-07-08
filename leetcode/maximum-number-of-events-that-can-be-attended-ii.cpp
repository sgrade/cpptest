// 1751. Maximum Number of Events That Can Be Attended II
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Top-down Dynamic Programming + Binary Search
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = events.size();
        this->k = k;
        memo.resize(k + 1, vector<int>(n, -1));
        sort(events.begin(), events.end());
        
        int ans = dfs(0, 0, events);
        return ans;
    }
private:
    int n, k;
    vector<vector<int>> memo;

    int dfs(int cur_idx, int events_so_far, vector<vector<int>>& events) {
        if (events_so_far == k || cur_idx == n)
            return 0;
        if (memo[events_so_far][cur_idx] != -1)
            return memo[events_so_far][cur_idx];
        int next_idx = bisectRight(events, events[cur_idx][1]);
        memo[events_so_far][cur_idx] = max(dfs(cur_idx + 1, events_so_far, events), events[cur_idx][2] + dfs(next_idx, events_so_far + 1, events));
        return memo[events_so_far][cur_idx];
    }

    int bisectRight(vector<vector<int>>& events, int target) {
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
