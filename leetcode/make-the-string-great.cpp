// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string makeGood(string s) {
        string ans = s;
        while (true) {
            bool check_again = false;
            for (int i = 0; i < ans.size(); ++i) {
                if (isupper(ans[i])) {
                    if (i > 0 && (islower(ans[i - 1]) && toupper(ans[i - 1]) == ans[i])) {
                        ans.erase(ans.begin() + i - 1, ans.begin() + i + 1);
                        check_again = true;
                        break;
                    }
                    else if (i + 1 < ans.size() && (islower(ans[i + 1]) && toupper(ans[i + 1]) == ans[i])) {
                        ans.erase(ans.begin() + i, ans.begin() + i + 2);
                        check_again = true;
                        break;
                    }
                }
            }
            if (!check_again)
                break;
        }
        return ans;
    }
};
