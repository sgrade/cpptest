// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int cnt = 0;
            for (int i = 0; i < k; ++i)
                cnt += blocks[i] == 'W';
            int ans = cnt;
            for (int i = k; i < blocks.size(); ++i) {
                cnt += blocks[i] == 'W';
                cnt -= blocks[i - k] == 'W';
                ans = min(ans, cnt);
            }
            return ans;
        }
    };
