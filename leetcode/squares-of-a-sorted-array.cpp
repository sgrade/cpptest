// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int& num: nums) {
            num *= num;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
