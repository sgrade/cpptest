// 1470. Shuffle the Array
// https://leetcode.com/problems/shuffle-the-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        ans[0] = nums[0];
        for (int i = 1, j = 2; i < n; ++i, j +=2) {
            ans[j] = nums[i];
        }
        for (int i = 1, j = n; i < n * 2; i += 2, ++j) {
            ans[i] = nums[j];
        }
        return ans;
    }
};
