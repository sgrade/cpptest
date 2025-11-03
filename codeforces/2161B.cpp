#include <bits/stdc++.h>

using namespace std;

// Editorial - https://codeforces.com/blog/entry/147941
// Based on https://codeforces.com/contest/2161/submission/346754300

bool IsValid(const unordered_set<int>& st) {
  if (st.size() <= 1) {
    return true;
  }
  auto [mn, mx] = minmax_element(st.begin(), st.end());
  return *mx - *mn <= 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        cin >> grid[r][c];
      }
    }

    unordered_set<int> rows, cols, diag, anti_diag;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (grid[r][c] != '#') {
          continue;
        }
        rows.emplace(r);
        cols.emplace(c);
        diag.emplace(r - c);
        anti_diag.emplace(r + c);
      }
    }

    bool ans = false;

    if (rows.empty()) {
      ans = true;
    }

    else if (IsValid(diag) || IsValid(anti_diag) ||
             (IsValid(rows) && IsValid(cols))) {
      ans = true;
    }

    cout << (ans ? "YES\n" : "NO\n");
  }

  return 0;
}
