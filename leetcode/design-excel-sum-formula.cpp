// 631. Design Excel Sum Formula
// https://leetcode.com/problems/design-excel-sum-formula/

#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Based on Editorial's Approach 1: Topological Sort
struct Formula {
  unordered_map<string, int> cells;
  int val;
  Formula(const unordered_map<string, int>& c, int v) : cells(c), val(v) {}
};

class Excel {
 public:
  Excel(int height, char width) {
    formulas_.assign(height, vector<Formula*>(width - 'A' + 1, nullptr));
  }

  void set(int r, char c, int v) {
    formulas_[r - 1][c - 'A'] = new Formula({}, v);
    TopologicalSort(r - 1, c - 'A');
    ExecuteStack();
  }

  int get(int r, char c) {
    if (formulas_[r - 1][c - 'A'] == nullptr) return 0;
    return formulas_[r - 1][c - 'A']->val;
  }

  int sum(int r, char c, vector<string> strs) {
    unordered_map<string, int> cells = Convert(strs);
    int summ = CalculateSum(r - 1, c - 'A', cells);
    set(r, c, summ);
    formulas_[r - 1][c - 'A'] = new Formula(cells, summ);
    return summ;
  }

 private:
  vector<vector<Formula*>> formulas_;
  stack<pair<int, int>> stack_;

  void TopologicalSort(int r, int c) {
    for (int i = 0; i < (int)formulas_.size(); i++) {
      for (int j = 0; j < (int)formulas_[0].size(); j++) {
        if (formulas_[i][j] != nullptr &&
            formulas_[i][j]->cells.count(string(1, 'A' + c) +
                                         to_string(r + 1))) {
          TopologicalSort(i, j);
        }
      }
    }
    stack_.push({r, c});
  }

  void ExecuteStack() {
    while (!stack_.empty()) {
      auto [r, c] = stack_.top();
      stack_.pop();
      if (!formulas_[r][c]->cells.empty()) {
        CalculateSum(r, c, formulas_[r][c]->cells);
      }
    }
  }

  unordered_map<string, int> Convert(const vector<string>& strs) {
    unordered_map<string, int> res;
    for (const string& s : strs) {
      if (s.find(':') == string::npos) {
        res[s]++;
      } else {
        size_t pos = s.find(':');
        string first = s.substr(0, pos);
        string second = s.substr(pos + 1);
        int si = stoi(first.substr(1));
        int ei = stoi(second.substr(1));
        char sj = first[0];
        char ej = second[0];
        for (int i = si; i <= ei; i++) {
          for (char j = sj; j <= ej; j++) {
            res[string(1, j) + to_string(i)]++;
          }
        }
      }
    }
    return res;
  }

  int CalculateSum(int r, int c, const unordered_map<string, int>& cells) {
    int sum = 0;
    for (const auto& [s, cnt] : cells) {
      int x = stoi(s.substr(1)) - 1;
      int y = s[0] - 'A';
      sum += (formulas_[x][y] != nullptr ? formulas_[x][y]->val : 0) * cnt;
    }
    formulas_[r][c] = new Formula(cells, sum);
    return sum;
  }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
