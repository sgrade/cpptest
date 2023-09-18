// 2824. Count Pairs Whose Sum is Less than Target
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] < target)
                    ++ans;
            }
        }
        return ans;
    }
};
