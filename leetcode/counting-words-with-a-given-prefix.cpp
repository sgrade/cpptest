// 2185. Counting Words With a Given Prefix
// https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0, n = pref.size();
        for (const string& word: words) {
            if (word.size() < n)
                continue;
            int i = 0;
            for (; i < n; ++i) {
                if (word[i] != pref[i])
                    break;
            }
            if (i == n)
                ++ans;
        }
        return ans;
    }
};
