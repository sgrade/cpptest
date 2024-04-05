// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string makeGood(string s) {
        while (true) {
            bool check_again = false;
            for (int i = 0; i < s.size(); ++i) {
                if (isupper(s[i])) {
                    if (i > 0 && (islower(s[i - 1]) && toupper(s[i - 1]) == s[i])) {
                        s.erase(s.begin() + i - 1, s.begin() + i + 1);
                        check_again = true;
                        break;
                    }
                    else if (i + 1 < s.size() && (islower(s[i + 1]) && toupper(s[i + 1]) == s[i])) {
                        s.erase(s.begin() + i, s.begin() + i + 2);
                        check_again = true;
                        break;
                    }
                }
            }
            if (!check_again)
                break;
        }
        return s;
    }
};
