// 2141. Maximum Running Time of N Computers
// https://leetcode.com/problems/maximum-running-time-of-n-computers/

#include <algorithm>
#include <numeric>
#include <vector>

using std::accumulate;
using std::sort;
using std::vector;

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    int b = batteries.size();
    sort(batteries.begin(), batteries.end());

    long long shared =
        accumulate(batteries.begin(), batteries.begin() + (b - n), 0LL);
    vector<int> n_largest(batteries.begin() + (b - n), batteries.end());

    for (int i = 0; i < n - 1; ++i) {
      int need = n_largest[i + 1] - n_largest[i];
      if (shared / (i + 1) < need) {
        long long have = shared / (i + 1);
        return n_largest[i] + have;
      }
      shared -= (i + 1) * need;
    }

    return n_largest[n - 1] + shared / n;
  }
};
