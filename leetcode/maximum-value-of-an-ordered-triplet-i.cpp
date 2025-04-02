// 2873. Maximum Value of an Ordered Triplet I
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size();
            long long ans = 0;
            for (int i = 0; i < n - 2; ++i) {
                for (int j = i + 1; j < n - 1; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        long long current_ans = 1LL * (nums[i] - nums[j]) * nums[k];
                        ans = max(ans, current_ans);
                    }
                }
            }
            return ans;
        }
    };
