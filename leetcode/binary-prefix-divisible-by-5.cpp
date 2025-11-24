// 1018. Binary Prefix Divisible By 5
// https://leetcode.com/problems/binary-prefix-divisible-by-5/

#include <vector>

using std::vector;

class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    int n = nums.size(), sm = 0;
    vector<bool> ans(n);
    for (int i = 0; i < n; ++i) {
      sm *= 2;
      sm = (sm + nums[i]) % 5;
      ans[i] = sm % 5 == 0;
    }
    return ans;
  }
};
