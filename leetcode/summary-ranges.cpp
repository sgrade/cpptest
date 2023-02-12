// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 1) return {to_string(nums[0])};
        vector<string> ans;
        int left = 0, right = 0;
        nums.emplace_back(0);
        while (right < nums.size() - 1) {
            ++right;
            if (nums[right] - 1 == nums[right - 1]) continue;
            if (right - left == 1) {
                ans.emplace_back(to_string(nums[left]));
            }
            else {
                ans.emplace_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
            }
            left = right;
        }
        return ans;
    }
};
