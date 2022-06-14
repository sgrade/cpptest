// 929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;
        for (string &email: emails) {
            uniq.insert(parse_email(email));
        }
        return uniq.size();
    }
    
    string parse_email (string s) {
        string output;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '+') {
                while (s[i] != '@') 
                    ++i;
            }
            if (s[i] == '@') {
                for (; i < s.size(); ++i) 
                    output += s[i];
                return output;
            }
            if (s[i] == '.') continue;
            output += s[i];
        }
        
        return output;
    }
};
