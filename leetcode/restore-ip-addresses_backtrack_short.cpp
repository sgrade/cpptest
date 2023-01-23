// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/restore-ip-addresses/submissions/883313670/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(s, ans, 0, 0, "");
        return ans;
    }
private:
    void backtrack(const string& s, vector<string>& ans, int idx, int octets, string current) {
        if (idx == s.size() && octets == 4) {
            current.pop_back();
            ans.emplace_back(current);
            return;
        }
        if (octets == 4) return;
        for (int i = idx, octet = 0; i < s.size(); ++i) {
            if (s[idx] == '0' && i > idx) return;
            octet = octet * 10 + s[i] - '0';
            if (octet < 256) backtrack(s, ans, i + 1, octets + 1, current + to_string(octet) + '.');
            else break;
        }
    }
};
