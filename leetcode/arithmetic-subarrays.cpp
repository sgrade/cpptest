// 1630. Arithmetic Subarrays
// https://leetcode.com/problems/arithmetic-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: No Sorting
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int subarrays = l.size();
        vector<bool> ans(subarrays);
        for (int i = 0; i < subarrays; ++i) {
            int& left = l[i], right = r[i];
            ans[i] = check(vector<int>(nums.begin() + left, nums.begin() + right + 1));
        }
        return ans;
    }
private:
    bool check (vector<int> v) {
        auto [mn, mx] = minmax_element(v.begin(), v.end());
        int n = v.size();
        if ((*mx - *mn) % (n - 1) != 0)
            return false;
        int d = ((*mx - *mn) / (n - 1));
        unordered_set<int> elements(v.begin(), v.end());
        int current = *mn + d;
        while (current < *mx) {
            if (elements.find(current) == elements.end())
                return false;
            current += d;
        }
        return true;
    }
};
