// 3487. Maximum Unique Subarray Sum After Deletion
// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positives;
        int ans = numeric_limits<int>::min();
        for (const int num: nums) {
            if (num > 0)
                positives.emplace(num);
            else
                ans = max(ans, num);
        }
        if (!positives.empty())
            ans = accumulate(positives.begin(), positives.end(), 0);
        return ans;
    }
};
