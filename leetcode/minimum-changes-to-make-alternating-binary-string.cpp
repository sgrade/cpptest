// 1758. Minimum Changes To Make Alternating Binary String
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(string s) {
        pair<char, char> x = {'0', '1'};
        int ans_zero = 0, ans_one;
        for (const char& ch: s) {
            if (ch != x.first)
                ++ans_zero;
            swap(x.first, x.second);
        }
        ans_one = s.size() - ans_zero;
        return min(ans_zero, ans_one);
    }
};
