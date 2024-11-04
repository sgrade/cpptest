// 3163. String Compression III
// https://leetcode.com/problems/string-compression-iii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string compressedString(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string ans;
        int i = 0;
        while (i < word.size()) {
            int j = i + 1;
            while (j < word.size() && word[j] == word[i])
                ++j;
            int cnt = j - i;
            while (cnt > 9) {
                ans += '9';
                ans += word[i];
                cnt -= 9;
            }
            ans += cnt + '0';
            ans += word[i];
            i = j;
        }
        return ans;
    }
};
