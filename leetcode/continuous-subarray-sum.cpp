// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Explanation - https://www.youtube.com/watch?v=OKcrLfR-8mE
        map<int, int> rems;
        rems[0] = -1;
        int sum = 0;
        int rem;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            rem = sum % k;
            if (rems.find(rem) == rems.end()) {
                rems[rem] = i;
            }
            else if (i - rems[rem] > 1) {
                return true;
            }
        }
        return false;
    }
};
