// Segment Tree Template
// Supports: Range Query, Point Update, Range Update (with Lazy Propagation)

#include <bits/stdc++.h>
using namespace std;

// ====================================================================================
// BASIC SEGMENT TREE - Range Sum Query with Point Update
// ====================================================================================
template <typename T>
class SegmentTree {
 private:
  vector<T> tree_;
  int n_;

  void Build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree_[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      Build(arr, 2 * node, start, mid);
      Build(arr, 2 * node + 1, mid + 1, end);
      tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
  }

  void Update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      tree_[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (idx <= mid) {
        Update(2 * node, start, mid, idx, val);
      } else {
        Update(2 * node + 1, mid + 1, end, idx, val);
      }
      tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
  }

  T Query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
      return 0;  // Identity value for sum (change for min/max)
    }
    if (l <= start && end <= r) {
      return tree_[node];
    }
    int mid = (start + end) / 2;
    T p1 = Query(2 * node, start, mid, l, r);
    T p2 = Query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
  }

 public:
  explicit SegmentTree(const vector<T>& arr) {
    n_ = arr.size();
    tree_.assign(4 * n_, 0);
    Build(arr, 1, 0, n_ - 1);
  }

  // Update value at index idx to val
  void Update(int idx, T val) { Update(1, 0, n_ - 1, idx, val); }

  // Query sum in range [l, r]
  T Query(int l, int r) { return Query(1, 0, n_ - 1, l, r); }
};

// ====================================================================================
// SEGMENT TREE WITH LAZY PROPAGATION - Range Update, Range Query
// ====================================================================================
template <typename T>
class LazySegmentTree {
 private:
  vector<T> tree_;
  vector<T> lazy_;
  int n_;

  void Build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree_[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      Build(arr, 2 * node, start, mid);
      Build(arr, 2 * node + 1, mid + 1, end);
      tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
  }

  void Push(int node, int start, int end) {
    if (lazy_[node] != 0) {
      tree_[node] += (end - start + 1) * lazy_[node];
      if (start != end) {
        lazy_[2 * node] += lazy_[node];
        lazy_[2 * node + 1] += lazy_[node];
      }
      lazy_[node] = 0;
    }
  }

  void UpdateRange(int node, int start, int end, int l, int r, T val) {
    Push(node, start, end);
    if (start > end || start > r || end < l) {
      return;
    }
    if (start >= l && end <= r) {
      lazy_[node] += val;
      Push(node, start, end);
      return;
    }
    int mid = (start + end) / 2;
    UpdateRange(2 * node, start, mid, l, r, val);
    UpdateRange(2 * node + 1, mid + 1, end, l, r, val);
    Push(2 * node, start, mid);
    Push(2 * node + 1, mid + 1, end);
    tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
  }

  T Query(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) {
      return 0;
    }
    Push(node, start, end);
    if (start >= l && end <= r) {
      return tree_[node];
    }
    int mid = (start + end) / 2;
    T p1 = Query(2 * node, start, mid, l, r);
    T p2 = Query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
  }

 public:
  explicit LazySegmentTree(const vector<T>& arr) {
    n_ = arr.size();
    tree_.assign(4 * n_, 0);
    lazy_.assign(4 * n_, 0);
    Build(arr, 1, 0, n_ - 1);
  }

  // Add val to all elements in range [l, r]
  void UpdateRange(int l, int r, T val) {
    UpdateRange(1, 0, n_ - 1, l, r, val);
  }

  // Query sum in range [l, r]
  T Query(int l, int r) { return Query(1, 0, n_ - 1, l, r); }
};

// ====================================================================================
// MIN/MAX SEGMENT TREE - Range Min/Max Query with Point Update
// ====================================================================================
template <typename T>
class MinSegmentTree {
 private:
  vector<T> tree_;
  int n_;
  T inf_;

  void Build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree_[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      Build(arr, 2 * node, start, mid);
      Build(arr, 2 * node + 1, mid + 1, end);
      tree_[node] = min(tree_[2 * node], tree_[2 * node + 1]);
    }
  }

  void Update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      tree_[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (idx <= mid) {
        Update(2 * node, start, mid, idx, val);
      } else {
        Update(2 * node + 1, mid + 1, end, idx, val);
      }
      tree_[node] = min(tree_[2 * node], tree_[2 * node + 1]);
    }
  }

  T Query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
      return inf_;
    }
    if (l <= start && end <= r) {
      return tree_[node];
    }
    int mid = (start + end) / 2;
    T p1 = Query(2 * node, start, mid, l, r);
    T p2 = Query(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
  }

 public:
  explicit MinSegmentTree(const vector<T>& arr,
                          T inf_value = numeric_limits<T>::max())
      : inf_(inf_value) {
    n_ = arr.size();
    tree_.assign(4 * n_, inf_);
    Build(arr, 1, 0, n_ - 1);
  }

  void Update(int idx, T val) { Update(1, 0, n_ - 1, idx, val); }

  T Query(int l, int r) { return Query(1, 0, n_ - 1, l, r); }
};

// ====================================================================================
// USAGE EXAMPLES
// ====================================================================================
void ExampleUsage() {
  // Example 1: Basic Sum Segment Tree
  vector<int> arr = {1, 3, 5, 7, 9, 11};
  SegmentTree<int> st(arr);
  cout << "Sum [1, 3]: " << st.Query(1, 3) << endl;  // 15
  st.Update(1, 10);
  cout << "Sum [1, 3] after update: " << st.Query(1, 3) << endl;  // 22

  // Example 2: Lazy Propagation Segment Tree
  vector<long long> arr2 = {1, 2, 3, 4, 5};
  LazySegmentTree<long long> lst(arr2);
  cout << "Sum [0, 4]: " << lst.Query(0, 4) << endl;  // 15
  lst.UpdateRange(1, 3, 10);  // Add 10 to elements [1, 3]
  cout << "Sum [0, 4] after range update: " << lst.Query(0, 4) << endl;  // 45

  // Example 3: Min Segment Tree
  vector<int> arr3 = {5, 2, 8, 1, 9, 3};
  MinSegmentTree<int> mst(arr3);
  cout << "Min [1, 4]: " << mst.Query(1, 4) << endl;  // 1
  mst.Update(3, 10);
  cout << "Min [1, 4] after update: " << mst.Query(1, 4) << endl;  // 2
}

// ====================================================================================
// COMMON VARIATIONS AND MODIFICATIONS
// ====================================================================================

/*
1. For MAX queries: Replace min() with max() and INF with -INF

2. For GCD/LCM queries: Replace merge operation with gcd()/lcm()

3. For XOR queries: Replace merge operation with XOR (^)

4. Range Assignment (instead of Range Addition):
   - In push(): tree[node] = lazy[node] * (end - start + 1)
   - Set lazy values directly instead of adding

5. 0-indexed vs 1-indexed:
   - This template uses 0-indexed input arrays
   - Internal tree uses 1-indexed nodes (node 1 is root)

6. Memory optimization:
   - Use 2*n instead of 4*n for tree size if n is power of 2
   - For dynamic segment tree, create nodes on demand

7. Persistent Segment Tree:
   - Create new nodes for each update instead of modifying existing ones
   - Useful for maintaining version history

8. 2D Segment Tree:
   - Build segment tree of segment trees
   - Useful for 2D range queries

Time Complexity:
- Build: O(n)
- Query: O(log n)
- Point Update: O(log n)
- Range Update (with lazy): O(log n)

Space Complexity: O(4n) = O(n)
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ExampleUsage();

  return 0;
}
