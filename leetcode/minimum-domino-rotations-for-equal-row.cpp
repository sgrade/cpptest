// 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            vector<int> top_counter(7), bot_counter(7);
            for (const int& x: tops)
                ++top_counter[x];
            for (const int& x: bottoms)
                ++bot_counter[x];

            int n = tops.size(), ans = n;
            for (int x = 1; x < 7; ++x) {
                int total = top_counter[x] + bot_counter[x];
                if (total < n)
                    continue;
                bool possible = true;
                for (int i = 0; i < n; ++i) {
                    if (tops[i] == bottoms[i])
                        --total;
                    if (total < n) {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                    continue;
                ans = min(n - top_counter[x], n - bot_counter[x]);
            }
            return ans == n ? -1 : ans;
        }
    };
