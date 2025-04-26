// 3375. Minimum Operations to Make Array Values Equal to K
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            set<int> st(nums.begin(), nums.end());
            if (*st.begin() < k)
                return -1;
            return st.size() - (st.find(k) != st.end());
        }
    };
