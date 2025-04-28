// 2302. Count Subarrays With Score Less Than K
// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sliding Window
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size();
            long long ans = 0, sum = 0;
            for (int i = 0, j = 0; j < n; ++j) {
                sum += nums[j];
                while (i <= j && sum * (j - i + 1) >= k)
                    sum -= nums[i++];
                ans += j - i + 1;
            }
            return ans;
        }
    };
