// 2176. Count Equal and Divisible Pairs in an Array
// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (nums[i] == nums[j] && i * j % k == 0)
                        ++ans;
                }
            }
            return ans;
        }
    };
