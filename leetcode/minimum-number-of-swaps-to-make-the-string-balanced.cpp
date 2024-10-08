// 1963. Minimum Number of Swaps to Make the String Balanced
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Space-Optimized Stack
class Solution {
public:
    int minSwaps(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int stack_size = 0;
        for (const char& ch: s) {
            if (ch == '[')
                ++stack_size;
            else {
                if (stack_size > 0)
                    --stack_size;
            }
        }
        return (stack_size + 1) / 2;
    }
};
