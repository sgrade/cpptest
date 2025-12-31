#include <bits/stdc++.h>

using namespace std;

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
