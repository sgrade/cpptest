// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Iterative Using a Stack
class Solution {
public:
    string getHappyString(int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        stack<string> st;
        int idx = 0;
        st.emplace("");

        while (!st.empty()) {
            string current = st.top();
            st.pop();
            if (current.size() == n) {
                ++idx;
                if (idx == k)
                    return current;
                continue;
            }
            for (char ch = 'c'; ch >= 'a'; --ch) {
                if (current.size() > 0 && current.back() == ch)
                    continue;
                st.emplace(current + ch);
            }
        }

        return "";
    }
};
