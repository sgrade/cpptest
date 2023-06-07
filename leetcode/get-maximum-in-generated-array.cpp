// 1646. Get Maximum in Generated Array
// https://leetcode.com/problems/get-maximum-in-generated-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        vector<int> nums(n + 1);
        nums[1] = 1;
        int ans = 1;
        for (int i = 1; i < n + 1; ++i) {
            if (2 * i <= n) {
                nums[2 * i] = nums[i];
            }
            if (2 * i + 1 <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
            ans = max(ans, nums[i]);
        }
        return ans;
        }
};
