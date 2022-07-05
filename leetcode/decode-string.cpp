// 394. Decode String
// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decode(s, index);
    }
    
    string decode(const string &s, int &index) {
        string ans;
        while (index < s.size() && s[index] != ']') {
            if (!isdigit(s[index])) {
                ans += s[index++];
            }
            else {
                int count = 0;
                while (index < s.size() && isdigit(s[index])) {
                    count = count * 10 + s[index++] - '0';
                }
                ++index;    // skip '['
                string tmp = decode(s, index);
                ++index;    // skip ']'
                while (count > 0) {
                    ans += tmp;
                    --count;
                }
            }
        }
        return ans;
    }
};
