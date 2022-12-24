// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>

using namespace std;

// SLOW
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        vector<int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            it = find(ans.begin(), ans.end(), nums[i]);
            if (it != ans.end()) {
                ans.erase(it);
                continue;
            }
            ans.emplace_back(nums[i]);
        }
        return ans;
    }
};
