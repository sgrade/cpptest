// 1071. Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans;

        if (str1.size() < str2.size())
            swap(str1, str2);
        size_t n1 = str1.size(), n2 = str2.size();

        for (int len = n2; len > 0; --len) {
            if (n1 % len != 0 || n2 % len != 0)
                continue;
            string current_candidate = str2.substr(0, len);
            size_t candidate_len = current_candidate.size();
            bool found1 = false, found2 = false;
            size_t i = 0;
            while (i < n2) {
                string tmp = str2.substr(i, candidate_len);
                if (tmp != current_candidate)
                    break;
            }
            if (i == n2) 
                found2 = true;
            i = 0;
            while (i < n1) {
                string tmp = str1.substr(i, candidate_len);
                if (tmp != current_candidate)
                    break;
            }
            if (i == n1)
                found1 = true;
            if (found1 && found2)
                return current_candidate;
        }

        return ans;
    }
};
