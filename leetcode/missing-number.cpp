// 268. Missing Number
// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};
