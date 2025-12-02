// 3623. Count Number of Trapezoids I
// https://leetcode.com/problems/count-number-of-trapezoids-i/

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<int, int> points_on_level;
    long long ans = 0, total_edges = 0;
    for (vector<int>& p : points) {
      points_on_level[p[1]]++;
    }
    for (const auto& [_, points] : points_on_level) {
      long long edges_on_level = (long long)points * (points - 1) / 2;
      ans += edges_on_level * total_edges % kMod;
      total_edges += edges_on_level;
    }
    return ans % kMod;
  }

 private:
  static constexpr int kMod = 1e9 + 7;
};
