// 2220. Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        int mask = 1;
        while (mask <= 1e9) {
            bool first = start & mask;
            bool second = goal & mask;
            if (first != second)
                ++ans;
            mask <<= 1;
        }
        return ans;
    }
};
