// 2147. Number of Ways to Divide a Long Corridor
// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

#include <string>
#include <vector>

using std::string;
using std::vector;

// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
 public:
  int numberOfWays(string corridor) {
    n = corridor.size();
    vector<vector<int>> cache(n, vector<int>(3, -1));
    return CountWays(0, 0, corridor, cache);
  }

 private:
  int n;
  static constexpr int kMod = 1e9 + 7;
  int CountWays(int idx, int seats, string& corridor,
                vector<vector<int>>& cache) {
    if (idx == n) {
      return seats == 2 ? 1 : 0;
    }
    if (cache[idx][seats] != -1) {
      return cache[idx][seats];
    }

    int ans = 0;
    if (seats == 2) {
      if (corridor[idx] == 'S') {
        ans = CountWays(idx + 1, 1, corridor, cache);
      } else {
        ans = (CountWays(idx + 1, 0, corridor, cache) +
               CountWays(idx + 1, 2, corridor, cache)) %
              kMod;
      }
    } else {
      if (corridor[idx] == 'S') {
        ans = CountWays(idx + 1, seats + 1, corridor, cache);
      } else {
        ans = CountWays(idx + 1, seats, corridor, cache);
      }
    }

    cache[idx][seats] = ans;
    return cache[idx][seats];
  }
};
