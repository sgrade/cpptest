// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Mark Visited Elements in the Input Array itself
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> ans;
        for (int& num: nums) {
            if (nums[abs(num) - 1] < 0)
                ans.emplace_back(abs(num));
            nums[abs(num) - 1] *= -1;
        }
        return ans;
    }
};
