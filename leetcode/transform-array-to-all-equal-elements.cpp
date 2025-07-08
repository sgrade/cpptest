// 3576. Transform Array to All Equal Elements
// https://leetcode.com/problems/transform-array-to-all-equal-elements/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        this->k = k;
        
        bool t1 = transform(nums, 1);
        if (t1)
            return true;
        bool t2 = transform(nums, -1);
        return t2;
    }

private:
    int n, k;
    bool transform(vector<int> nums, int target) {
        int ops = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != target) {
                nums[i] *= -1;
                nums[i + 1] *= -1;
                ++ops;
            }
            if (ops > k)
                return false;
        }
        return nums[n - 1] == target;
    }
};
