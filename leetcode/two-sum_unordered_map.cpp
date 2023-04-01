// 1. Two Sum
// https://leetcode.com/problems/two-sum/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int complement;
        for (int i = 0; i < nums.size(); ++i) {
            complement = target - nums[i];
            if (mp.find(complement) != mp.end())
                return vector<int> {i, mp[complement]};
            mp[nums[i]] = i;
        }
        return {};
    }
};
