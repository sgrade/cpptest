// 1758. Minimum Changes To Make Alternating Binary String
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(string s) {
        pair<char, char> x = {'0', '1'};
        int ans_zero = 0, ans_one = 0;
        for (const char& ch: s) {
            if (ch != x.first)
                ++ans_zero;
            if (ch != x.second)
                ++ans_one;
            swap(x.first, x.second);
        }
        return min(ans_zero, ans_one);
    }
};
