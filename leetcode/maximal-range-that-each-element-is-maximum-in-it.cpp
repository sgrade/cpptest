// 2832. Maximal Range That Each Element Is Maximum in It
// https://leetcode.com/problems/maximal-range-that-each-element-is-maximum-in-it/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Monotonic Stack
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<int> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = right[i] - left[i] - 1;
        return ans;
    }
};
