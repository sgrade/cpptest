// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from a sample solution
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int duplicate;
        vector<int> ans(2);
        for (const int& num: nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0)
                duplicate = abs(num);
            else
                nums[idx] = -nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans[0] = duplicate;
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};
