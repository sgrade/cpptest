// 2560. House Robber IV
// https://leetcode.com/problems/house-robber-iv/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Binary Search
class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            
            int n = nums.size(), mn = 1, mx = *max_element(nums.begin(), nums.end());
            while (mn < mx) {
                int mid = mn + (mx - mn) / 2;
                int thefts = 0;
                for (int i = 0; i < n; ++i) {
                    if (nums[i] <= mid) {
                        thefts += 1;
                        ++i;
                    }
                }
                if (thefts >= k)
                    mx = mid;
                else
                    mn = mid + 1;
            }
            return mn;
        }
    };
    