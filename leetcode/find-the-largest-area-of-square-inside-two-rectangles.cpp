// 3047. Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/

#include <algorithm>
#include <vector>

using namespace std;

// Based on Editorial's Approach: Traversal + Computational Geometry
class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int n = bottomLeft.size();
    int max_side = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int width = min(topRight[i][0], topRight[j][0]) -
                    max(bottomLeft[i][0], bottomLeft[j][0]);
        int height = min(topRight[i][1], topRight[j][1]) -
                     max(bottomLeft[i][1], bottomLeft[j][1]);
        max_side = max(max_side, min(width, height));
      }
    }

    return static_cast<long long>(max_side) * max_side;
  }
};
