// 2355. Maximum Number of Books You Can Take
// https://leetcode.com/problems/maximum-number-of-books-you-can-take/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        n = books.size();
        stack<int> st;
        vector<long long> dp(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && books[st.top()] - st.top() >= books[i] - i)
                st.pop();
            if (st.empty())
                dp[i] = calculateSum(0, i, books);
            else {
                int j = st.top();
                dp[i] = dp[j] + calculateSum(j + 1, i, books);
            }
            st.emplace(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
private:
    int n;
    long long calculateSum (int l, int r, vector<int>& books) {
        long long cnt = min(books[r], r - l + 1);
        return (2 * books[r] - (cnt - 1)) * cnt / 2;
    }
};
