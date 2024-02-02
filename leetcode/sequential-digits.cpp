// 1291. Sequential Digits
// https://leetcode.com/problems/sequential-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 10; ++i) {
            int x = i, y = i + 1;
            while (x < low && y < 10) {
                x *= 10;
                x += y;
                ++y;
            }
            if (x < low)
                continue;
            while (x <= high && y <= 10) {
                ans.emplace_back(x);
                x *= 10;
                x += y;
                ++y;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
