// 961. N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    for (size_t diff = 1; diff < 4; ++diff) {
      for (size_t i = 0; i < nums.size() - diff; ++i) {
        if (nums[i] == nums[i + diff]) {
          return nums[i];
        }
      }
    }
    return -1;
  }
};
