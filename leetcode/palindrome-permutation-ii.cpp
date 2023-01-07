// 267. Palindrome Permutation II
// https://leetcode.com/problems/palindrome-permutation-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcodes's Approach #2 Backtracking
class Solution {
public:
    vector<string> ans;
    vector<string> generatePalindromes(string s) {
       map<char, int> counter;
        vector<char> st(s.size() / 2);
        if (!CanPermutePalindrome(s, counter)) {
            return vector<string>();
        }
        char ch = '0';
        int k = 0;
        for (int i = 0; i < counter.size(); ++i) {
            if (counter[i] % 2 == 1) {
                ch = (char) i;
            }
            for (int j = 0; j < counter[i] / 2; ++j) {
                st[k++] = (char) i;
            }
        }
        permute(st, 0, ch);
        return ans;
    }

private:
    bool CanPermutePalindrome(string s, map<char, int>& counter) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++counter[s[i]];
            if (counter[s[i]] % 2 == 0) {
                --count;
            }
            else {
                ++count;
            }
        }
        return count <= 1;
    }

    void permute(vector<char> s, int l, char ch) {
        if (l == s.size()) {
            string current;
            for (const char& ch: s) {
                current += ch;
            }
            if (ch != '0') {
                current += ch;
            }
            for (int i = s.size() - 1; i >= 0; --i) {
                current += s[i];
            }
            ans.emplace_back(current);
        }
        else {
            for (int i = l; i < s.size(); ++i) {
                if (s[l] != s[i] || l == i) {
                    swap(s[l], s[i]);
                    permute(s, l + 1, ch);
                    swap(s[l], s[i]);
                }
            }
        }
    }
};
