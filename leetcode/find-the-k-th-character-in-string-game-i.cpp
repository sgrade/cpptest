// 3304. Find the K-th Character in String Game I
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    char kthCharacter(int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        string s = "a";
        while (s.size() < k) {
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                char ch = 'a' + (s[i] - 'a' + 1) % 26;
                s += ch;
            }
        }
        return s[k - 1];
    }
};
