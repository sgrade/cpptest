// 2975. Maximum Square Area by Removing Fences From a Field
// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

// Based on Editorial's Approach: Enumeration (Optimized)
class Solution {
 public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences,
                         vector<int>& vFences) {
    vector<int> h_positions = hFences;
    h_positions.emplace_back(1);
    h_positions.emplace_back(m);
    sort(h_positions.begin(), h_positions.end());

    vector<int> v_positions = vFences;
    v_positions.emplace_back(1);
    v_positions.emplace_back(n);
    sort(v_positions.begin(), v_positions.end());

    // Generate all possible edge lengths for horizontal
    unordered_set<int> h_edges;
    size_t h_size = h_positions.size();
    h_edges.reserve(h_size * (h_size - 1) / 2);
    for (size_t i = 0; i < h_size; ++i) {
      for (size_t j = i + 1; j < h_size; ++j) {
        h_edges.insert(h_positions[j] - h_positions[i]);
      }
    }

    // Find maximum common edge by checking vertical edges
    int ans = 0;
    size_t v_size = v_positions.size();
    for (size_t i = 0; i < v_size; ++i) {
      for (size_t j = i + 1; j < v_size; ++j) {
        int edge = v_positions[j] - v_positions[i];
        if (h_edges.count(edge)) {
          ans = max(ans, edge);
        }
      }
    }

    if (ans == 0) {
      return -1;
    }

    return static_cast<long long>(ans) * ans % kMod;
  }

 private:
  static constexpr int kMod = 1e9 + 7;
};
