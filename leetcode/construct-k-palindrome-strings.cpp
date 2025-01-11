// 400. Construct K Palindrome Strings
// https://leetcode.com/problems/construct-k-palindrome-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canConstruct(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (s.size() < k)
            return false;
        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];

        int odd = 0;
        for (int i = 0; i < 26; ++i)
            odd += counter[i] % 2;

        return odd <= k;;
    }
};
