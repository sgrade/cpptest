// 1970. Last Day Where You Can Still Cross
// https://leetcode.com/problems/last-day-where-you-can-still-cross/

#include <numeric>
#include <vector>

using namespace std;

// Based on Editorial's Approach 3: Disjoint Set Union (on land cells)
class UnionFind {
 public:
  explicit UnionFind(int size) : parent_(size), rank_(size) {
    iota(parent_.begin(), parent_.end(), 0);
  }
  int Find(int x) {
    if (x != parent_[x]) parent_[x] = Find(parent_[x]);
    return parent_[x];
  }
  void UnionSet(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);
    if (root_x == root_y) return;
    if (rank_[root_x] < rank_[root_y]) {
      parent_[root_x] = root_y;
    } else if (rank_[root_y] < rank_[root_x]) {
      parent_[root_y] = root_x;
    } else {
      parent_[root_y] = root_x;
      ++rank_[root_x];
    }
  }
  bool Connected(int x, int y) { return Find(x) == Find(y); }

 private:
  vector<int> parent_;
  vector<int> rank_;
};

class Solution {
 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    UnionFind dsu(row * col + 2);
    vector<vector<int>> grid(
        row, vector<int>(col, 1));  // Initialize to all water (1)
    const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int day = cells.size() - 1; day >= 0; --day) {
      int r = cells[day][0] - 1;
      int c = cells[day][1] - 1;
      grid[r][c] = 0;  // Convert water (1) to land (0)
      int idx1 = r * col + c + 1;
      for (const auto& [r_diff, c_diff] : directions) {
        int new_r = r + r_diff;
        int new_c = c + c_diff;
        int idx2 = new_r * col + new_c + 1;
        if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col &&
            grid[new_r][new_c] == 0) {  // Check if neighbor is land (0)
          dsu.UnionSet(idx1, idx2);
        }
      }
      if (r == 0) {
        dsu.UnionSet(0, idx1);
      }
      if (r == row - 1) {
        dsu.UnionSet(row * col + 1, idx1);
      }
      if (dsu.Find(0) == dsu.Find(row * col + 1)) {
        return day;
      }
    }

    return -1;
  }
};
