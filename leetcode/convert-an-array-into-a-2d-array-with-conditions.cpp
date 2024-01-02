// 2610. Convert an Array Into a 2D Array With Conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& el: nums)
            ++counter[el];
        vector<vector<int>> ans;
        for (const auto& [num, cnt]: counter) {
            int n = ans.size();
            n = min(n, cnt);
            int i = 0;
            for (; i < n; ++i)
                ans[i].emplace_back(num);
            for (; i < cnt; ++i)
                ans.emplace_back(vector<int>{num});
        }
        return ans;
    }
};
