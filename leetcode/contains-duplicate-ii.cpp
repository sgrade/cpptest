// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            if (indexes.find(nums[i]) != indexes.end()) {
                if (i - indexes[nums[i]] <= k) {
                    return true;
                }
                else {
                    indexes[nums[i]] = i;
                }
            }
            else {
                indexes[nums[i]] = i;
            }
        }
        return false;
    }
};
