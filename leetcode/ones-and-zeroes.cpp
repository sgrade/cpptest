// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/

#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (const string& s : strs) {
      int zeroes = count(s.begin(), s.end(), '0');
      int ones = s.size() - zeroes;
      for (int z = m; z >= zeroes; --z) {
        for (int o = n; o >= ones; --o) {
          dp[z][o] = max(dp[z][o], 1 + dp[z - zeroes][o - ones]);
        }
      }
    }
    return dp[m][n];
  }
};