// 1957. Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        // Optimized with an idea from the fastest solutions
        if (s.size() > 2){
            int j = 2;
            for (int i = 2; i < s.size(); ++i)
                if (s[i] != s[j - 1] || s[i] != s[j - 2]) s[j++] = s[i];
            s.resize(j);
        }
        return s;
    }
};
