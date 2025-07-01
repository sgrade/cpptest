// 3330. Find the Original Typed String I
// https://leetcode.com/problems/find-the-original-typed-string-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int possibleStringCount(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1])
                ++ans;
        }
        return ans;
    }
};
