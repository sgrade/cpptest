// 3201. Find the Maximum Length of Valid Subsequence I
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Parity of Enumeration Elements
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ans = 0;
        vector<vector<bool>> patterns = {{false, false}, {false, true}, {true, false}, {true, true}};
        for (vector<bool>& pattern: patterns) {
            int current_ans = 0;
            for (const int& num: nums) {
                int parity = current_ans % 2;
                if (num % 2 == pattern[parity])
                    ++current_ans;
            }
            ans = max(ans, current_ans);
        }
        return ans;
    }
};
