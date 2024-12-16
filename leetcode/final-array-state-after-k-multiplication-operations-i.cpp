// 3264. Final Array State After K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        set<pair<int, int>> st;
        for (int i = 0; i < nums.size(); ++i)
            st.emplace(nums[i], i);
        while (k--) {
            auto [num, idx] = *st.begin();
            num *= multiplier;
            st.erase(st.begin());
            st.emplace(num, idx);
        }
        for (const auto& [num, idx]: st)
            nums[idx] = num;
        return nums;
    }
};
