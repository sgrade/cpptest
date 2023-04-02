// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 1) {
            ans.emplace_back(to_string(nums[0]));
            return ans;
        }
        int left = 0, right = 1, n = nums.size();
        while (right < nums.size()) {
            if (nums[right] - 1 == nums[right - 1]) {
                ++right;
                continue;
            }
            AddToAns (nums, left, right);
            left = right;
            right = left + 1;
        }
        if (left < n) {
            AddToAns (nums, left, right);
        }
        return ans;
    }
private:
    vector<string> ans;
    void AddToAns (vector<int>& nums, int& left, int& right) {
        if (right - 1 == left) {
            ans.emplace_back(to_string(nums[left]));
        }
        else {
            ans.emplace_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
        }
    }
};
