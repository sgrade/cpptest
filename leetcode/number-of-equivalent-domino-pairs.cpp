// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_map<int, int> counter;
            for (vector<int>& v: dominoes) {
                if (v[0] > v[1])
                    swap(v[0], v[1]);
                ++counter[v[0] * 1e5 + v[1]];
            }

            int ans = 0;
            for (const auto& [_, cnt]: counter)
                ans += cnt * (cnt - 1) / 2;
            return ans;
        }
    };
