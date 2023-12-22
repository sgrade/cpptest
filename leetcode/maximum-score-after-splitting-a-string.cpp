// 1422. Maximum Score After Splitting a String
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: One Pass
class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0, zeroes = 0, best = numeric_limits<int>::min();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1')
                ++ones;
            else
                ++zeroes;
            best = max(best, zeroes - ones);
        }
        if (s[n - 1] == '1')
            ++ones;
        return best + ones;
    }
};
