// 267. Palindrome Permutation II
// https://leetcode.com/problems/palindrome-permutation-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcodes's Approach #2 Backtracking
class Solution {
public:
    set<string> ans;
    vector<string> generatePalindromes(string s) {
       map<char, int> counter;
        string st;
        if (!CanPermutePalindrome(s, counter)) {
            return vector<string>();
        }
        char mid_ch = '0';
        for (auto &[ch, count]: counter) {
            if (count % 2 == 1) {
                mid_ch = ch;
            }
            for (int j = 0; j < count / 2; ++j) {
                st += ch;
            }
        }
        permute(st, 0, mid_ch);
        return vector<string>(ans.begin(), ans.end());
    }

private:
    bool CanPermutePalindrome(string s, map<char, int>& counter) {
        int odd = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++counter[s[i]];
        }
        for (auto &[_, count]: counter) {
            if (count % 2 != 0) {
                ++odd;
            }
        }
        return odd <= 1;
    }

    void permute(string st, int l, char mid_ch) {
        if (l == st.size()) {
            string current = st;
            if (mid_ch != '0') {
                current += mid_ch;
            };
            reverse(st.begin(), st.end());
            current += st;
            ans.emplace(current);
        }
        else {
            for (int i = l; i < st.size(); ++i) {
                if (st[l] != st[i] || l == i) {
                    swap(st[l], st[i]);
                    permute(st, l + 1, mid_ch);
                    swap(st[l], st[i]);
                }
            }
        }
    }
};
