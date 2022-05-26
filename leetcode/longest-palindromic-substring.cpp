// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// https://www.youtube.com/watch?v=UflHuQj6MVA
// https://github.com/mission-peace/interview/blob/master/C%2B%2B/Dynamic%20Programming/Longest%20palindromic%20Subsequence.cpp

#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {

        int maxLen = 0;
        string ans;
        ans += s[0];
        
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for (int i = 0; i < n; ++i) {
            int j = i;
            dp[i][j] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            if (s[i] == s[j]) {
                dp[i][j] = true;
                if (2 > maxLen) {
                    maxLen = 2;
                    ans = s.substr(i, 2);
                }
            }
            else{
                dp[i][j] = false;
            }
        }

        for (int len = 3; len < n + 1; ++len) {
            int i = 0, j = len - 1;
            while (j < n) {
                if (s[i] == s[j] && (dp[i+1][i+1] && dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        ans = s.substr(i, len);
                    }
                }
                ++i;
                ++j;
            }
        }
        
        return ans;
    }
};


int main() {

    string s = "cc";

    Solution sol;   
    string ans = sol.longestPalindrome(s);
    cout << ans << '\n';

    return 0;
}
