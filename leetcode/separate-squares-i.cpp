// 3453. Separate Squares I
// https://leetcode.com/problems/separate-squares-i/

#include <algorithm>
#include <vector>

using namespace std;

// Based on Editorial' Approach 1: Binary Search
class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    double max_y = 0;
    double total_area = 0;
    for (const vector<int>& sq : squares) {
      int y = sq[1];
      int side = sq[2];
      total_area += static_cast<double>(side) * side;
      max_y = max(max_y, static_cast<double>(y + side));
    }

    auto has_half_area_below = [&](double target_y) -> bool {
      double area_below_target = 0;
      for (const vector<int>& sq : squares) {
        int y = sq[1];
        int side = sq[2];
        if (y < target_y) {
          area_below_target +=
              side * min(target_y - y, static_cast<double>(side));
        }
      }
      return area_below_target >= total_area / 2;
    };

    double lo = 0;
    double hi = max_y;
    const double precision = 1e-5;
    while (abs(hi - lo) > precision) {
      double mid = (hi + lo) / 2;
      if (has_half_area_below(mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    return hi;
  }
};
