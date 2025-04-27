// 3392. Count Subarrays of Length Three With a Condition
// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int ans = 0, sum;
            float half;
            for (int i = 2; i < nums.size(); ++i) {
                sum = nums[i - 2] + nums[i];
                half = nums[i - 1] / 2.0;
                ans += sum == half;
            }
            return ans;
        }
    };
