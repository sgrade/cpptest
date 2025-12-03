// 3625. Count Number of Trapezoids II
// https://leetcode.com/problems/count-number-of-trapezoids-ii/

#include <climits>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// Based on Editorial's Approach: Hash Table + Geometry Mathematics
class Solution {
 public:
  int countTrapezoids(vector<vector<int>>& points) {
    int n = points.size();
    unordered_map<float, vector<float>> slope_to_intercept;
    unordered_map<long long, vector<float>> mid_to_slope;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        int x2 = points[j][0], y2 = points[j][1];
        int dx = x1 - x2, dy = y1 - y2;
        float slope, intercept;
        if (x2 == x1) {
          slope = INT_MAX;
          intercept = x1;
        } else {
          slope = (float)(y2 - y1) / (x2 - x1);
          intercept = (float)(y1 * dx - x1 * dy) / dx;
        }
        long long mid = (long long)(x1 + x2) * 10000 + (y1 + y2);
        slope_to_intercept[slope].emplace_back(intercept);
        mid_to_slope[mid].emplace_back(slope);
      }
    }

    for (const auto& [_, sti] : slope_to_intercept) {
      if (sti.size() == 1) {
        continue;
      }
      unordered_map<float, int> counter;
      for (const float intercept : sti) {
        counter[intercept]++;
      }
      int edges = 0;
      for (const auto& [_, cnt] : counter) {
        ans += edges * cnt;
        edges += cnt;
      }
    }

    for (const auto& [_, mts] : mid_to_slope) {
      if (mts.size() == 1) {
        continue;
      }
      unordered_map<float, int> counter;
      for (const float slope : mts) {
        counter[slope]++;
      }
      int edges = 0;
      for (const auto& [_, cnt] : counter) {
        ans -= edges * cnt;
        edges += cnt;
      }
    }

    return ans;
  }
};