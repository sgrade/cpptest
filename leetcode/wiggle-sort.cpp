// 280. Wiggle Sort
// https://leetcode.com/problems/wiggle-sort/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                if (i % 2 == 0) {
                    swap(nums[i], nums[i + 1]);
                }
            }
            else if (nums[i] < nums[i + 1]) {
                if (i % 2 == 1) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
};
