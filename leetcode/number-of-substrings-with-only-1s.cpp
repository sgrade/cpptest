// 1513. Number of Substrings With Only 1s
// https://leetcode.com/problems/number-of-substrings-with-only-1s/

#include <string>

using std::string;

class Solution {
 public:
  int numSub(string s) {
    static constexpr int kMod = 1e9 + 7;
    int ans = 0, n = s.size(), ones = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        ones = 0;
        continue;
      }
      ++ones;
      ans += ones;
      ans %= kMod;
    }
    return ans;
  }
};
