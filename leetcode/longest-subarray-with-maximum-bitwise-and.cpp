// 2419. Longest Subarray With Maximum Bitwise AND
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Longest consecutive sequence of the maximum value
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int mx = 0, ans = 0, current_ans = 0;
        for (const int& num: nums) {
            if (num > mx) {
                mx = num;
                ans = 0;
                current_ans = 0;
            }
            if (num == mx)
                ++current_ans;
            else
                current_ans = 0;
            ans = max(ans, current_ans);
        }
        return ans;
    }
};
