// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Prefix Sum
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0, sum = 0;
        unordered_map<int, int> freq;
        for (const int& num: nums) {
            sum += num;
            if (sum == goal)
                ++ans;
            int need = sum - goal;
            if (freq.find(need) != freq.end())
                ans += freq[need];
            ++freq[sum];
        }
        return ans;
    }
};
