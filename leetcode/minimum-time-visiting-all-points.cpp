// 1266. Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0;
    for (size_t i = 1; i < points.size(); ++i) {
      int d0 = abs(points[i][0] - points[i - 1][0]);
      int d1 = abs(points[i][1] - points[i - 1][1]);
      ans += max(d0, d1);
    }
    return ans;
  }
};
