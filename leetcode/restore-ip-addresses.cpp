// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Backtracking (DFS)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        backtrack(s, n, ans, -1, 3);
        return ans;
    }

private:
    vector<string> segments;
    
    bool IsValid (string segment) {
        if (segment.size() <= 3 && !(segment[0] == '0' && segment.size() != 1) && stoi(segment) <= 255) {
            return true;
        }
        else {
            return false;
        }
        
    }
    
    void update_ans (const string &s, int cur_pos, vector<string> &ans) {
        string segment = s.substr(cur_pos + 1);
        if (IsValid(segment)) {
            string ip = "";
            for (const string &octet: segments) {
                ip += octet;
                ip += ".";
            }
            ip += segment;
            ans.emplace_back(ip);
        }
    }
    
    void backtrack (const string &s, const int &n, vector<string> &ans, int prev_pos, int dots) {
        int max_pos = min(n - 1, prev_pos + 4);
        for (int cur_pos = prev_pos + 1; cur_pos < max_pos; cur_pos++) {
            string segment = s.substr(prev_pos + 1, cur_pos - prev_pos);
            if (IsValid(segment)) {
                segments.emplace_back(segment);
                if (dots - 1 == 0) {
                    update_ans(s, cur_pos, ans);
                }
                else {
                    backtrack(s, n, ans, cur_pos, dots - 1);
                }
                segments.pop_back();
            }
        }
    }
};
