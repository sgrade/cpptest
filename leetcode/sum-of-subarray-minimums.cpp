// 907. Sum of Subarray Minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Monotonic Stack
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long ans = 0;
        int n = arr.size();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int left_boundary = st.empty() ? -1 : st.top();
                int right_boundary = i;
                long count = (mid - left_boundary) * (right_boundary - mid) % MOD;
                ans += (count * arr[mid]) % MOD;
                ans %= MOD;
            }
            st.emplace(i);
        }    
        return ans;
    }
private:
    int MOD = 1e9 + 7;

};
