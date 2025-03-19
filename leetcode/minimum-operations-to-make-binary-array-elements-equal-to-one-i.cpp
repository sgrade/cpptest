// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

#include <bits/stdc++.h

using namespace std;


class Solution {
    public:
        int minOperations(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ans = 0;
            for (int i = 0; i < nums.size() - 2; ++i) {
                if (nums[i] == 1)
                    continue;
                ++ans;
                for (int j = i; j < i + 3; ++j)
                    nums[j] = !nums[j];
            }
            for (int i = nums.size() - 2; i < nums.size(); ++i) {
                if (nums[i] == 0)
                    return -1;
            }
            return ans;
        }
    };
