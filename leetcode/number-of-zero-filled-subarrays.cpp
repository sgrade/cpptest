// 2348. Number of Zero-Filled Subarrays
// https://leetcode.com/problems/number-of-zero-filled-subarrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long ans = 0, cnt = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ans += ++cnt;
            else cnt = 0;
        }
        return ans;
    }
};
