// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>

using namespace std;

// SLOW
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        bool flag;
        for (int i = 0; i < nums.size(); ++i) {
            flag = false;
            for (int j = 0; j < ans.size(); ++j) {
                if (ans[j] == nums[i]) {
                    ans.erase(ans.begin() + j);
                    flag = true;
                    break;
                }
            }
            if (!flag) ans.emplace_back(nums[i]);
        }
        return ans;
    }
};
