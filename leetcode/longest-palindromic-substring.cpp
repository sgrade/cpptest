// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

/* 
Expand Around Center.
There are 2*n - 1 centers.
If s.size() is even, the center of a palindrome is in between two letters. 
E.g. in "axxa" the center is between the two x's.
Complexity: time O(n^2), space O(1).
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, cur_len;
        if (s.size() == 0) return "";

        int left = 0;
        for (int center = 0; center < s.size(); ++center) {
            int odd = ExpandAroundCenter(s, center, center);
            int even = ExpandAroundCenter(s, center, center + 1);
            cur_len = max(odd, even);
            if (cur_len > max_len) {
                left = center - (cur_len - 1) / 2;
                max_len = cur_len;
            }
        }
        return s.substr(left, max_len);
    }

private:
    int ExpandAroundCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};


int main() {

    string s = "axxa";

    Solution sol;   
    string ans = sol.longestPalindrome(s);
    cout << ans << '\n';

    return 0;
}
