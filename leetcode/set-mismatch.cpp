// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        vector<int> ans(2);
        unordered_map<int, int> cntr;
        for (const int& num: nums)
            ++cntr[num];
        for (int i = 1; i <= nums.size(); ++i) {
            if (cntr.find(i) == cntr.end())
                ans[1] = i;
            if (cntr[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};
