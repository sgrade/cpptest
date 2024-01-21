// 907. Sum of Subarray Minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Monotonic Stack + Dynamic Programming
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        stack<int> st;
        int n = arr.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty()) {
                int previous_smaller = st.top();
                dp[i] = dp[previous_smaller] + (i - previous_smaller) * arr[i];
            }
            else
                dp[i] = (i + 1) * arr[i];
            st.emplace(i);
        }
        long ans = 0;
        for (const int& cnt: dp) {
            ans += cnt;
            ans %= MOD;
        }
        return ans;
    }
private:
    int MOD = 1e9 + 7;
};
