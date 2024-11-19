// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        map<int, int> counter;
        int duplicates = 0;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            ++counter[nums[i]];
            if (counter[nums[i]] > 1)
                ++duplicates;
            sum += nums[i];
        }

        long long ans = duplicates == 0 ? sum : 0;
        for (int left = 0, right = k; right < nums.size(); ++left, ++right) {
            sum -= nums[left];
            sum += nums[right];
            if (counter[nums[left]] > 1)
                --duplicates;
            --counter[nums[left]];
            ++counter[nums[right]];
            if (counter[nums[right]] > 1)
                ++duplicates;
            if (duplicates == 0)
                ans = max(ans, sum);
        }
        return ans;
    }
};
