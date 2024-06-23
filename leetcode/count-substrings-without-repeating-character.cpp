// 2743. Count Substrings Without Repeating Character
// https://leetcode.com/problems/count-substrings-without-repeating-character/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size(), left = 0, ans = 0, substrings = 0;
        vector<int> counter(26);
        for (int right = 0; right < n; ++right) {
            int right_idx = s[right] - 'a';
            ++counter[right_idx];
            ++substrings;
            while (counter[right_idx] > 1) {
                --substrings;
                int left_idx = s[left++] - 'a';
                --counter[left_idx];
            }
            ans += substrings;
        }
        return ans;
    }
};
