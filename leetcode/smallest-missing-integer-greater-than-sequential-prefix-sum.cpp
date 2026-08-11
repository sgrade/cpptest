// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int sm = nums[0];
    size_t i = 1;
    for (; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == 1) {
        sm += nums[i];
      } else {
        break;
      }
    }

    set<int> st(nums.begin(), nums.end());
    while (st.count(sm)) {
      ++sm;
    }
    return sm;
  }
};
