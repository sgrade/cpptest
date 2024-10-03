// 1590. Make Sum Divisible by P
// https://leetcode.com/problems/make-sum-divisible-by-p/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Prefix Sum Modulo
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size(), sum = 0;
        for (const int& num: nums)
            sum = (sum + num) % p;
        int target = sum % p;
        if (target == 0)
            return 0;
        unordered_map<int, int> mods;
        mods[0] = -1;
        int current_sum = 0, ans = n;
        for (int i = 0; i < n; ++i) {
            current_sum = (current_sum + nums[i]) % p;
            int need = (current_sum - target + p) % p;
            if (mods.find(need) != mods.end())
                ans = min(ans, i - mods[need]);
            mods[current_sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};
