// 962. Maximum Width Ramp
// https://leetcode.com/problems/maximum-width-ramp/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Monotonic Stack
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()])
                st.emplace(i);
        }

        int ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                int current_ans = j - st.top();
                ans = max(ans, current_ans);
                st.pop();
            }
        }
        return ans;
    }
};
