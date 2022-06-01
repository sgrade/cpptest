// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
