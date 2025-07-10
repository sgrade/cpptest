// 3572. Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values
// https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> nums;
        for (int i = 0; i < x.size(); ++i)
            nums[x[i]] = max(nums[x[i]], y[i]);
        if (nums.size() < 3)
            return -1;
        
        vector<int> vals(3);
        for (const auto& [_, num]: nums) {
            if (num > vals[2]) {
                vals.pop_back();
                vals.emplace_back(num);
                sort(vals.begin(), vals.end(), greater<int>());
            }
        }
        int ans = accumulate(vals.begin(), vals.end(), 0);
        return ans;
    }
};
