// 3335. Total Characters in String After Transformations I
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Recurrence
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> current(26);
        for (const char& ch: s)
            ++current[ch - 'a'];
        for (int round = 0; round < t; ++round) {
            vector<int> next(26);
            next[0] = current[25];
            next[1] = (current[25] + current[0]) % MOD;
            for (int i = 2; i < 26; ++i)
                next[i] = current[i - 1];
            current = next;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
            ans = (ans + current[i]) % MOD;
        return ans;
    }

private:
    const int MOD = 1e9 + 7;
};
