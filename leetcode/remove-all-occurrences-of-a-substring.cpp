// 1910. Remove All Occurrences of a Substring
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part), n = part.size();
        while (pos != string::npos) {
            s.erase(pos, n);
            pos = s.find(part);
        }
        return s;
    }
};
