// 3403. Find the Lexicographically Largest String From the Box I
// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Enumeration
class Solution {
public:
    string answerString(string word, int numFriends) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (numFriends == 1)
            return word;
        int n = word.size();
        string ans;
        for (int i = 0; i < n; ++i)
            ans = max(ans, word.substr(i, min(n - numFriends + 1, n - i)));
        return ans;
    }
};
