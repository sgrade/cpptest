// 1298. Maximum Candies You Can Get from Boxes
// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

#include <bits/stdc++.h>;

using namespace std;


// Based on Editorial's Maximum Candies You Can Get from Boxes
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = status.size();
        vector<bool> can_open(n), has_box(n), used(n);
        for (int i = 0; i < n; ++i)
            can_open[i] = status[i] == 1;

        queue<int> q;
        int ans = 0;
        for (const int& box: initialBoxes) {
            has_box[box] = true;
            if (can_open[box]) {
                q.emplace(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (const int& key : keys[cur]) {
                can_open[key] = true;
                if (!used[key] && has_box[key]) {
                    q.emplace(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for (const int& box: containedBoxes[cur]) {
                has_box[box] = true;
                if (!used[box] && can_open[box]) {
                    q.emplace(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }
        return ans;
    }
};
