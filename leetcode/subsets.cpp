// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        GetSubset(nums, 0, {});
        return vector<vector<int>>(st.begin(), st.end());
    }

private:
    int n;
    set<vector<int>> st;
    void GetSubset (vector<int>& nums, int idx, vector<int> current) {
        if (idx == n) {
            st.emplace(current);
            return;
        }
        current.emplace_back(nums[idx]);
        GetSubset(nums, idx + 1, current);
        current.pop_back();
        GetSubset(nums, idx + 1, current);
    }
};
