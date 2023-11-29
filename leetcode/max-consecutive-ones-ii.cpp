// 487. Max Consecutive Ones II
// https://leetcode.com/problems/max-consecutive-ones-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int left = 0, right = 0, zeroes = 0;
        int ans = 1;

        while (right < n) {
            if (nums[right] == 0)
                ++zeroes;
            while (zeroes == 2) {
                if (nums[left] == 0)
                    --zeroes;
                ++left;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};
