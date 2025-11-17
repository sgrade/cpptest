// 1437. Check If All 1's Are at Least Length K Places Away
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

#include <algorithm>
#include <vector>

using std::distance;
using std::find;
using std::vector;

class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    vector<int>::iterator prev = find(nums.begin(), nums.end(), 1);
    while (prev != nums.end()) {
      vector<int>::iterator cur = find(prev + 1, nums.end(), 1);
      if (cur != nums.end()) {
        int dist = distance(prev, cur) - 1;
        if (dist < k) {
          return false;
        }
      }
      prev = cur;
    }
    return true;
  }
};
