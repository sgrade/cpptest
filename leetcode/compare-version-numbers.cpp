// 65. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<int> v1, v2;
    void parseS(const string& s, vector<int>& v) {
        int n = s.size();
        int i = 0, idx = 0;
        int x;
        while (i < n) {
            x = 0;
            
            // Skip leading zeroes
            while (i < n && s[i] == '0') ++i;
            
            if (i == n) break;
            
            if (s[i] == '.') {
                v.push_back(x);
                ++i;
                continue;
            }
            
            // Parsing digits
            while(i < n && isdigit(s[i])) {
                x = x * 10 + (s[i] - '0');
                ++i;
            }
            v.push_back(x);
        }
    }

public:
    int compareVersion(string version1, string version2) {
        parseS(version1, v1);
        parseS(version2, v2);
        while (v1.size() < v2.size()) v1.push_back(0);
        while (v2.size() < v1.size()) v2.push_back(0);
        if (v1 < v2) return -1;
        else if (v1 > v2) return 1;
        else return 0;
    }
};
