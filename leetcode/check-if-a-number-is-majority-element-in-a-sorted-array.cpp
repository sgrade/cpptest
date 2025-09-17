// 1150. Check If a Number Is Majority Element in a Sorted Array
// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

#include <vector>
#include <algorithm>

using std::vector;
using std::count;


class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = count(nums.begin(), nums.end(), target);
        return cnt > nums.size() / 2;
    }
};
