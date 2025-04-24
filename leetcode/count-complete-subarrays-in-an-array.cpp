// 2799. Count Complete Subarrays in an Array
// https://leetcode.com/problems/count-complete-subarrays-in-an-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sliding Window
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_set<int> distinct(nums.begin(), nums.end());
            int total_distinct = distinct.size();

            int cur_distinct = 0, right = 0, ans = 0, n = nums.size();
            vector<int> counter(2001);

            for (int left = 0; left < n; ++left) {
                if (left > 0) {
                    int x = nums[left - 1];
                    --counter[x];
                    if (counter[x] == 0)
                        --cur_distinct;
                }

                while (right < n && cur_distinct < total_distinct) {
                    int x = nums[right];
                    if (counter[x] == 0)
                        ++cur_distinct;
                    ++counter[x];
                    ++right;
                }

                if (cur_distinct == total_distinct)
                    ans += (n - right + 1);
            }

            return ans;
        }
    };
