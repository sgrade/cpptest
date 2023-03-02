// 443. String Compression
// https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        prev = chars[0], len = 0, idx = 0;
        for (int i = 0; i < chars.size(); ++i) {
            if (chars[i] == prev)
                ++len;
            else {
                append(chars);
                len = 1;
                prev = chars[i];
            }
        }
        append(chars);
        return idx;
    }
private:
    char prev;
    int len, idx;
    string len_s;
    void append(vector<char>& chars) {
        chars[idx++] = prev;
        if (len == 1) return;
        len_s = to_string(len);
        for (const char& ch: len_s) {
            chars[idx++] = ch;
        }
    }
};
