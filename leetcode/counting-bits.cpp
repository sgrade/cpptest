// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 4: DP + Last Set Bit
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        // We flip the least significant one bit (i & (i - 1)), so the count is increased by 1.
        for (int i = 1; i < n + 1; ++i)
            ans[i] = ans[i & (i - 1)] + 1;
        return ans;
    }
};
