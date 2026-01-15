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

    int h_max = longest_consequitive(hBars);
    int v_max = longest_consequitive(vBars);

    int side = min(h_max, v_max) + 1;
    return side * side;
  }

 private:
  int longest_consequitive(vector<int>& v) {
    if (v.size() == 0) {
      return 0;
    }
    int max_len = 1;
    int cur_len = 1;
    for (size_t i = 1; i < v.size(); i++) {
      if (v[i] == v[i - 1] + 1) {
        ++cur_len;
      } else {
        cur_len = 1;
      }
      max_len = max(cur_len, max_len);
    }
    return max_len;
  }
};
