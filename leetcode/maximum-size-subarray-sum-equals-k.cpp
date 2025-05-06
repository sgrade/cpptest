// 325. Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int maxSubArrayLen(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), ans = 0;
            long sum = 0;
            unordered_map<long, int> indexes;
            for (int right = 0; right < n; ++right) {
                sum += nums[right];
                if (sum == k)
                    ans = right + 1;
                long sum_without_k = sum - k;
                if (indexes.find(sum_without_k) != indexes.end()) {
                    int left = indexes[sum_without_k];
                    ans = max(ans, right - left);
                }

                if (indexes.find(sum) == indexes.end())
                    indexes[sum] = right;
            }
            return ans;
        }
    };
