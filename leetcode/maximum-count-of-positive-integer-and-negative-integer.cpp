// 2529. Maximum Count of Positive Integer and Negative Integer
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int pos = 0, neg = 0, i = 0;
            for (; i < nums.size() && nums[i] < 0; ++i)
                ++neg;
            for (; i < nums.size() && nums[i] == 0; ++i)
                continue;
            pos = nums.size() - i;
            return max(neg, pos);
        }
    };
