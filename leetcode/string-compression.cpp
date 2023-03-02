// 443. String Compression
// https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0, idx = 0;
        size_t i = 0, j, n = chars.size();
        while (i < n) {
            j = i + 1;
            while (j < n && chars[j] == chars[i]) 
                ++j;
            
            chars[idx++] = chars[i];
            len = j - i;
            if (len > 1) {
                string len_s = to_string(len);
                for (const char& ch: len_s)
                    chars[idx++] = ch;
            }

            i = j;
        }
        return idx;
    }
};
