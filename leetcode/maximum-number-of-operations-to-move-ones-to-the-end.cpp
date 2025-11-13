// 3228. Maximum Number of Operations to Move Ones to the End
// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/

#include <string>

using std::string;

class Solution {
 public:
  int maxOperations(string s) {
    int ops = 0, zero_intervals = 0, i = s.size() - 1;
    while (i >= 0) {
      if (s[i] == '0') {
        ++zero_intervals;
        while (i >= 0 && s[i] == '0') {
          --i;
        }
      } else {
        int ones = 0;
        while (i >= 0 && s[i] == '1') {
          ++ones;
          --i;
        }
        ops += ones * zero_intervals;
      }
    }
    return ops;
  }
};
