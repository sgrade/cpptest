// 679. 24 Game
// https://leetcode.com/problems/24-game/

#include <vector>
#include <cmath>

using namespace std;


// Based on Editorial's Approach 1: Backtracking
class Solution {
 public:
  bool judgePoint24(const vector<int>& cards) {
    vector<double> current_cards(cards.begin(), cards.end());
    return Backtrack(current_cards);
  }

 private:
  static constexpr double kEpsilon = 1e-6;

  bool Backtrack(vector<double>& current_cards) const {
    if (current_cards.size() == 1) {
      return fabs(current_cards[0] - 24) < kEpsilon;
    }
    for (size_t i = 0; i < current_cards.size(); ++i) {
      for (size_t j = 0; j < current_cards.size(); ++j) {
        if (i == j) {
            continue;
        }
        vector<double> next_cards;
        for (size_t k = 0; k < current_cards.size(); ++k) {
          if (k != i && k != j) next_cards.emplace_back(current_cards[k]);
        }
        for (double res : Generate(current_cards[i], current_cards[j])) {
          next_cards.emplace_back(res);
          if (Backtrack(next_cards)) {
            return true;
          }
          next_cards.pop_back();
        }
      }
    }
    return false;
  }

  vector<double> Generate(double a, double b) const {
    vector<double> results = {a + b, a - b, b - a, a * b};
    if (fabs(a) > kEpsilon) {
        results.push_back(b / a);
    }
    if (fabs(b) > kEpsilon) {
        results.push_back(a / b);
    }
    return results;
  }
};
