// 401. Binary Watch
// https://leetcode.com/problems/binary-watch/

#include <bits/stdc++.h>

using namespace std;


// Idea from https://leetcode.com/problems/binary-watch/solutions/926686/easy-bit-count-solution-c
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                int bits_set = __builtin_popcount(h) + __builtin_popcount(m);
                if (bits_set == turnedOn)
                    ans.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
        }
        return ans;
    }
};
