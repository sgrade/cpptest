// 3289. The Two Sneaky Numbers of Digitville
// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (const int num : nums) {
      ++counter[num];
    }
    vector<int> ans;
    for (const auto& [num, cnt] : counter) {
      if (cnt == 2) {
        ans.emplace_back(num);
      }
    }
    return ans;
  }
};