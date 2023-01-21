// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>

using namespace std;


// NOT FINISHED
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       vector<string> ans; 
    }
private:
    bool IsValid (string s) {
        if (s[0] == '0') {
            if (s.size() == 1) {
                return true;
            }
            return false;
        int octet = stoi(s);
        if (octet < 256) {
            return true;
        }
        return false;
    }
    void Backtrack (const string& s, vector<string>& ans, string current, string last, int dots, int idx) {
        if (current.size() - 3 == s.size()) {
            if (IsValid(last)) {
                ans.emplace(current);
            }
            return;
        }
        if (last.size() < 3) {
            last += s[idx];
            backtrack(s, ans, current, last, idx + 1);
            last.pop_back();
        }
        else if (last.size() == 3) {
            current
        }
    }
};
