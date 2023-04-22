// 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && isspace(s[i]))
                ++i;
            if (i < s.size() && !isspace(s[i]))
                ++ans;
            while (i < s.size() && !isspace(s[i]))
                ++i;
        }
        return ans;
    }
};
