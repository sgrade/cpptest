// 3517. Smallest Palindromic Rearrangement I
// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

#include <string>

using namespace std;

class Solution {
 public:
  string smallestPalindrome(string s) {
    int n = s.size();
    int cnt[26] = {};
    for (char c : s) {
      ++cnt[c - 'a'];
    }

    string ans(n, ' ');
    int left = 0;
    int mid = -1;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] & 1) {
        mid = i;
      }
      int half = cnt[i] / 2;
      char ch = 'a' + i;
      for (int j = 0; j < half; ++j) {
        ans[left] = ch;
        ans[n - 1 - left] = ch;
        ++left;
      }
    }
    if (mid != -1) {
      ans[n / 2] = 'a' + mid;
    }
    return ans;
  }
};
