// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        int left = lower, right;
        for (int i = 0; i < nums.size() + 1; ++i) {
            right = i == nums.size() ? upper + 1 : nums[i];
            if (right - left == 1) {
                ans.emplace_back(to_string(left));
            }
            else if (right - left > 1) {
                ans.emplace_back(to_string(left) + "->" + to_string(right - 1));
            }
            left = right + 1;
        }
        
        return ans;
    }
};
