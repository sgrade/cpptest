// 2364. Count Number of Bad Pairs
// https://leetcode.com/problems/count-number-of-bad-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<int, int> counter;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = i - nums[i];
            ans += i - counter[diff];
            ++counter[diff];
        }
        return ans;
    }
};
