// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>

using namespace std;


// Some ideas are based on https://leetcode.com/problems/restore-ip-addresses/solutions/2868540/restore-ip-addresses/comments/1767097
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       vector<string> ans;
       vector<string> octets;
       Backtrack(s, ans, octets, 0);
       return ans;
    }
private:
    bool IsValidOctet (string octet) {
        if (octet[0] == '0') {
            if (octet.size() == 1) {
                return true;
            }
            return false;
        }
        return stoi(octet) <= 255;
    }

    void Backtrack (const string& s, vector<string>& ans, vector<string>& octets, int idx) {
        if (octets.size() == 4 && idx == s.size()) {
            string ip;
            for (const string& octet: octets) {
                ip += octet;
                ip += '.';
            }
            ip.pop_back();
            ans.emplace_back(ip);
            return;
        }

        for (int len = 1; len < 4 && idx + len <= s.size(); ++len) {
            string octet = s.substr(idx, len);
            if (!IsValidOctet(octet)) {
                break;
            }
            if (octets.size() < 4) {
                octets.emplace_back(octet);
                Backtrack (s, ans, octets, idx + len);
                octets.pop_back();
            }
        }
   }
};

int main() {

    string str;
    cin >> str;

    Solution sol;
    vector<string> output = sol.restoreIpAddresses(str);

    for (const string& o: output) {
        cout << o << endl;
    }

    return 0;
}