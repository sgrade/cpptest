// 1165. Single-Row Keyboard
// https://leetcode.com/problems/single-row-keyboard/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int ans = 0;
        int prev_pos = 0, next_pos;
        for (int i = 0; i < word.size(); ++i) {
            next_pos = keyboard.find(word[i]);
            ans += abs(next_pos - prev_pos);
            prev_pos = next_pos;
        }
        return ans;
    }
};
