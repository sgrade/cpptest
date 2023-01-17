// 926. Flip String to Monotone Increasing
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Dynamic Programming
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, ones = 0;
        for (const char& ch: s) {
            if (ch =='0') {
                ans = min(ones, ans + 1);
            }
            else {
                ++ones;
            }
        }
        return ans;
    }
};
