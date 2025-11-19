// 2154. Keep Multiplying Found Values by Two
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> st(nums.begin(), nums.end());
    while (st.count(original)) {
      original *= 2;
    }
    return original;
  }
};
