// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Using Stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 2 * (n - 1); i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i % n])
                st.pop();
            ans[i % n] = st.empty() ? -1 : nums[st.top()];
            st.emplace(i % n);
        }
        return ans;
    }
};
