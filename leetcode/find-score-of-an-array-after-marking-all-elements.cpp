// 2593. Find Score of an Array After Marking All Elements
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; ++i)
            sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());

        long long score = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            int idx = sorted[i].second;
            if (visited[idx])
                continue;
            score += sorted[i].first;
            visited[idx] = true;
            int prev = idx - 1;
            if (prev >= 0)
                visited[prev] = true;
            int next = idx + 1;
            if (next < n)
                visited[next] = true;
        }
        return score;
    }
};
