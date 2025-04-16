// 2537. Count the Number of Good Subarrays
// https://leetcode.com/problems/count-the-number-of-good-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Two pointers
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), equal = 0, right = -1;
            unordered_map<int, int> counter;
            long long ans = 0;
            for (int left = 0; left < n; ++left) {
                while (equal < k && right + 1 < n) {
                    ++right;
                    equal += counter[nums[right]];
                    ++counter[nums[right]];
                }
                if (equal >= k)
                    ans += n - right;
                --counter[nums[left]];
                equal -= counter[nums[left]];
            }
            return ans;
        }
    };
