// 922. Sort Array By Parity II
// https://leetcode.com/problems/sort-array-by-parity-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int even = 0, odd = 1, n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                ans[even] = nums[i];
                even += 2;
            }
            else {
                ans[odd] = nums[i];
                odd += 2;
            }
        }
        return ans;
    }
};
