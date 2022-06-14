// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> a;
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) a.push_back(toupper(s[i]));
        }
        int rem = a.size() % k;
        int i = 0;
        string ans;
        for (; i < rem; ++i) {
            ans += a[i];
        }
        if (rem > 0 && i < a.size()) 
                ans += '-';
        while (i < a.size()) {
            for (int j = 0; j < k; ++j, ++i) ans += a[i]; 
            if (i < a.size()) 
                ans += '-';
        }
        return ans;
    }
};
