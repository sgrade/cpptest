// 468. Validate IP Address
// https://leetcode.com/problems/validate-ip-address/

#include <bits/stdc++.h>

using namespace std;

// The solution is slow. Needs redesign.
class Solution {
public:
    string validIPAddress(string queryIP) {
        // regexes are from here - https://leetcode.com/problems/validate-ip-address/discuss/690534/C%2B%2B-Oneliner-2-Regexes-(Lazily-Evaluated)-Solution-Explained-~15-Time-~15-Space
        regex ipv4_regex("^(?:(?:25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9]?[0-9])\\.){3}(?:25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9]?[0-9])$"); 
        regex ipv6_regex("^(([0-9a-fA-F]{1,4}:){1,7}[0-9a-fA-F]{1,4})$");
        
        if (regex_match(queryIP, ipv4_regex)) {
            return "IPv4";
        }
        else if (regex_match(queryIP, ipv6_regex)) {
            return "IPv6";
        }
        return "Neither";
    }
};
