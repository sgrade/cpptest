// 2434. Using a Robot to Print the Lexicographically Smallest String
// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

#include <bits/stdc++.h>

using namespace std;


// Used ideas from Editorial's Approach: Greedy + Stack
class Solution {
public:
    string robotWithString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        map<char, int> counter;
        for (const char& ch: s)
            ++counter[ch];
        string ans;
        stack<char> st;
        char mn = counter.begin()->first;
        for (const char& ch: s) {
            st.emplace(ch);
            --counter[ch];
            if (counter[ch] == 0) {
                counter.erase(ch);
                mn = counter.empty() ? 'z' : counter.begin()->first;
            }
            while (!st.empty() && st.top() <= mn) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};
