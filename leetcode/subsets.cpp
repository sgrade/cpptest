// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        GetSubset(nums, 0, {});
        return ans;
    }

private:
    int n;
    vector<vector<int>> ans;
    void GetSubset (vector<int>& nums, int idx, vector<int> current) {
        if (idx == n) {
            ans.emplace_back(current);
            return;
        }
        current.emplace_back(nums[idx]);
        GetSubset(nums, idx + 1, current);
        current.pop_back();
        GetSubset(nums, idx + 1, current);
    }
};
