// 992. Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window in One Pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        int n = nums.size(), left = 0, right = 0, count = 0;
        unordered_map<int, int> counter;
        while (right < n) {
            ++counter[nums[right]];
            if (counter[nums[right]] == 1)
                --k;
            ++right;

            if (k < 0) {
                --counter[nums[left++]];
                ++k;
                count = 0;
            }

            if (k == 0) {
                while (counter[nums[left]] > 1) {
                    --counter[nums[left++]];
                    ++count;
                }
                ans += count + 1;
            }
        }
        return ans;
    }
};
