// 3517. Smallest Palindromic Rearrangement I
// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string smallestPalindrome(string s) {
    int n = s.size();
    vector<int> counter(26);
    for (int i = 0; i < n; ++i) {
      int idx = s[i] - 'a';
      counter[idx]++;
    }

    int mid = -1;
    string ans = "";
    for (int i = 0; i < 26; i++) {
      if (counter[i] % 2 != 0) {
        mid = i;
      }
      int cnt = counter[i] / 2;
      char ch = 'a' + i;
      for (int j = 0; j < cnt; ++j) {
        ans += ch;
      }
    }
    if (mid != -1) {
      ans += 'a' + mid;
    }
    for (int j = n / 2 - 1; j >= 0; j--) {
      ans += ans[j];
    }
    return ans;
  }
};
