// 1887. Reduction Operations to Make the Array Elements Equal
// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort (nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1])
                ans += n - i;
        }
        return ans;
    }
};
