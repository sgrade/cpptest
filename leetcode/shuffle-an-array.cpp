// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2 Fisher-Yates Algorithm
// Modified with ideas from a sample fast solution
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int> tmp(nums);
        int n = tmp.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap (tmp[i], tmp[j]);
        }
        return tmp;
    }

private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
