// 499. The Maze III
// https://leetcode.com/problems/the-maze-iii/

#include <queue>
#include <string>
#include <vector>

using namespace std;

// Based on Editorial's Approach: Dijkstra's
struct State {
  int row;
  int col;
  int dist;
  string path;

  State(int r, int c, int d, string p) : row(r), col(c), dist(d), path(p) {}
};

struct StateComparator {
  bool operator()(const State& a, const State& b) const {
    if (a.dist == b.dist) {
      return a.path > b.path;  // For lexicographically smaller path
    }
    return a.dist > b.dist;  // For min-heap
  }
};

class Solution {
 public:
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball,
                         vector<int>& hole) {
    rows = maze.size();
    cols = maze[0].size();

    priority_queue<State, vector<State>, StateComparator> heap;
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    heap.push(State(ball[0], ball[1], 0, ""));

    while (!heap.empty()) {
      State curr = heap.top();
      heap.pop();

      int row = curr.row;
      int col = curr.col;

      if (seen[row][col]) {
        continue;
      }

      if (row == hole[0] && col == hole[1]) {
        return curr.path;
      }

      seen[row][col] = true;

      for (State& next_state : GetNeighbors(row, col, maze, hole)) {
        int next_row = next_state.row;
        int next_col = next_state.col;
        int next_dist = next_state.dist;
        string next_char = next_state.path;
        heap.push(State(next_row, next_col, curr.dist + next_dist,
                        curr.path + next_char));
      }
    }

    return "impossible";
  }

 private:
  vector<vector<int>> directions_ = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  vector<string> text_directions_ = {"l", "u", "r", "d"};
  int rows;
  int cols;

  bool Valid(int row, int col, vector<vector<int>>& maze) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      return false;
    }
    return maze[row][col] == 0;
  }

  vector<State> GetNeighbors(int row, int col, vector<vector<int>>& maze,
                             vector<int>& hole) {
    vector<State> neighbors;

    for (int i = 0; i < 4; i++) {
      int row_diff = directions_[i][0];
      int col_diff = directions_[i][1];
      string direction = text_directions_[i];

      int cur_row = row;
      int cur_col = col;
      int dist = 0;

      while (Valid(cur_row + row_diff, cur_col + col_diff, maze)) {
        cur_row += row_diff;
        cur_col += col_diff;
        dist++;
        if (cur_row == hole[0] && cur_col == hole[1]) {
          break;
        }
      }

      neighbors.push_back(State(cur_row, cur_col, dist, direction));
    }

    return neighbors;
  }
};