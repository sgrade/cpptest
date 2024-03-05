// 1750. Minimum Length of String After Deleting Similar Ends
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (s.size() == 1)
            return 1;
        int left = 0, right = s.size() - 1;
        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left < right && s[left] == ch)
                ++left;
            while (left < right && s[right] == ch)
                --right;
        }
        if (left == right) {
            if (s[left - 1] == s[right])
                return 0;
            else
                return 1;
        }
        return right - left + 1;
    }
};
