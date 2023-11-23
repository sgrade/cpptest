// 1630. Arithmetic Subarrays
// https://leetcode.com/problems/arithmetic-subarrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int subarrays = l.size();
        vector<bool> ans(subarrays);
        for (int i = 0; i < subarrays; ++i) {
            int left = l[i], right = r[i];
            ans[i] = check(vector<int>(nums.begin() + left, nums.begin() + right + 1));
        }
        return ans;
    }
private:
    bool check (vector<int> v) {
        int n = v.size();
        if (n < 3)
            return true;
        sort(v.begin(), v.end());
        int d = v[1] - v[0];
        for (int i = 2; i < n; ++i) {
            if (v[i] - v[i - 1] != d)
                return false;
        }
        return true;
    }
};
