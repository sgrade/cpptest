// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> counter;
        counter[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (counter.find(sum - k) != counter.end()) {
                ans += counter[sum - k];
            }
            ++counter[sum];
        }
        return ans;
    }
};
