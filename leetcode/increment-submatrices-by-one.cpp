// 2536. Increment Submatrices by One
// https://leetcode.com/problems/increment-submatrices-by-one/

#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> diff_arr(n + 1, vector<int>(n + 1));
    for (vector<int>& q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      diff_arr[r1][c1]++;
      diff_arr[r2 + 1][c1]--;
      diff_arr[r1][c2 + 1]--;
      diff_arr[r2 + 1][c2 + 1]++;
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        int col_diff = r == 0 ? 0 : ans[r - 1][c];
        int row_diff = c == 0 ? 0 : ans[r][c - 1];
        int diag_diff = (r == 0 || c == 0) ? 0 : ans[r - 1][c - 1];
        ans[r][c] = diff_arr[r][c] + col_diff + row_diff - diag_diff;
      }
    }
    return ans;
  }
};
