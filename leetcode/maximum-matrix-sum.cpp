// 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long total = 0;
    int min_abs = INT_MAX;
    int negatives = 0;
    for (const vector<int>& row : matrix) {
      for (const int num : row) {
        int cur_abs = abs(num);
        total += cur_abs;
        min_abs = min(min_abs, cur_abs);
        if (num < 0) ++negatives;
      }
    }
    if (negatives % 2 != 0) total -= 2 * min_abs;
    return total;
  }
};
