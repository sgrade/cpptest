// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

#include <vector>

using namespace std;

// Based on Editorial's Approach 2: Dynamic Programming - Better Brute Force on
// Histograms
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int ans = 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col)
        if (matrix[row][col] == '1') {
          // Compute the maximum width of a rectangle that ends at a given
          // coordinate
          dp[row][col] = col == 0 ? 1 : dp[row][col - 1] + 1;
          int width = dp[row][col];
          // Compute the maximum rectangle with the lower right corner at that
          // coordinate
          for (int r = row; r >= 0; --r) {
            width = min(width, dp[r][col]);
            ans = max(ans, width * (row - r + 1));
          }
        }
    }
    return ans;
  }
};
