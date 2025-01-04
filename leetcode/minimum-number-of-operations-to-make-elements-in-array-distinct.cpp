// 3396. Minimum Number of Operations to Make Elements in Array Distinct
// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_set<int> seen;
        int n = nums.size();
        int i = n - 1;
        for (; i >= 0; --i) {
            if (seen.find(nums[i]) != seen.end())
                break;
            seen.emplace(nums[i]);
        }
        if (seen.size() == n)
            return 0;
        return i / 3 + 1; 
    }
};
