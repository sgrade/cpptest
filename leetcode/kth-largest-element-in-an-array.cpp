// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>

using namespace std;

// NOTE: Consider other ways to solve it (heap, quick select)
// https://leetcode.com/problems/kth-largest-element-in-an-array/solution/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
