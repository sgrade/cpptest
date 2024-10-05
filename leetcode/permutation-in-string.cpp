// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (s1.size() > s2.size())
            return false;

        vector<int> counter1(26);
        for (const char& ch: s1)
            ++counter1[ch - 'a'];

        int left = 0, right = 0;
        vector<int> counter2(26);
        while (right < s1.size())
            ++counter2[s2[right++] - 'a'];

        while (right <= s2.size()) {
            bool found = true;
            for (int i = 0; i < 26; ++i) {
                if (counter1[i] != counter2[i]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
            int idx1 = s2[left++] - 'a';
            --counter2[idx1];
            if (right < s2.size()) {
                int idx2 = s2[right++] - 'a';
                ++counter2[idx2];
            }
            else
                ++right;
        }
        return false;
    }
};
