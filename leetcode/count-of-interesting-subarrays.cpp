// 2845. Count of Interesting Subarrays
// https://leetcode.com/problems/count-of-interesting-subarrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            long long ans = 0;
            unordered_map<int, int> counter;
            int prefix_cnt = 0;
            counter[0] = 1;
            for (const int& num: nums) {
                prefix_cnt += num % modulo == k;
                ans += counter[(prefix_cnt - k + modulo) % modulo];
                ++counter[prefix_cnt % modulo];
            }

            return ans;
        }
    };
