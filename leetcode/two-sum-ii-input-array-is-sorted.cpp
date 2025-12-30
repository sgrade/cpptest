// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int lo = 0, hi = numbers.size() - 1;
    while (lo < hi) {
      int total = numbers[lo] + numbers[hi];
      if (total == target) {
        return vector<int>{lo + 1, hi + 1};
      } else if (total < target) {
        lo++;
      } else {
        hi--;
      }
    }
    return {};
  }
};
