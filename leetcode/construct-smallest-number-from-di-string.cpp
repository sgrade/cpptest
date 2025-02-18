// 2375. Construct Smallest Number From DI String
// https://leetcode.com/problems/construct-smallest-number-from-di-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Using Stack
class Solution {
public:
    string smallestNumber(string pattern) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = pattern.size();
        string ans;
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            st.emplace(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};
