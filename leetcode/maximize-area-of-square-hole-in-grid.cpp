// 3027. Maximize Area of Square Hole in Grid
// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/

#include <algorithm>
#include <vector>

using namespace std;

// Find longest consecutive sequences in both bar arrays.
// Time: O(n log n + m log m), Space: O(1)
class Solution {
 public:
  int maximizeSquareHoleArea(int /*n*/, int /*m*/, vector<int>& hBars,
                             vector<int>& vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());
    int h_max = 1;
    int v_max = 1;
    int h_cur = 1;
    int v_cur = 1;

    for (size_t i = 1; i < hBars.size(); i++) {
      if (hBars[i] == hBars[i - 1] + 1) {
        ++h_cur;
      } else {
        h_cur = 1;
      }
      h_max = max(h_max, h_cur);
    }

    for (size_t i = 1; i < vBars.size(); i++) {
      if (vBars[i] == vBars[i - 1] + 1) {
        ++v_cur;
      } else {
        v_cur = 1;
      }
      v_max = max(v_max, v_cur);
    }

    int side = min(h_max, v_max) + 1;
    return side * side;
  }
};
