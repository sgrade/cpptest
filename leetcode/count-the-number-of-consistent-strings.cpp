// 1684. Count the Number of Consistent Strings
// https://leetcode.com/problems/count-the-number-of-consistent-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<bool> chars(26);
        for (const char& ch: allowed)
            chars[ch - 'a'] = true;
        int ans = 0;
        for (const string& word: words) {
            bool consistent = true;
            for (const char& ch: word) {
                if (!chars[ch - 'a']) {
                    consistent = false;
                    break;
                }
            }
            ans += consistent;
        }
        return ans;
    }
};
