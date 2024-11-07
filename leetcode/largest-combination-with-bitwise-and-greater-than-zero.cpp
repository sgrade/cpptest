// 2275. Largest Combination With Bitwise AND Greater Than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> bits(24);
        for (int i = 0; i < 24; ++i) {
            int bit = 1 << i;
            for (const int& candidate: candidates)
                bits[i] += (candidate & bit) != 0;
        }
        int ans = 0;
        for (int i = 0; i < 24; ++i)
            ans = max (ans, bits[i]);
        return ans;
    }
};
