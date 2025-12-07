// 1523. Count Odd Numbers in an Interval Range
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
 public:
  int countOdds(int low, int high) {
    int ans = (high - low + 1) / 2 + (low % 2 == 1 && high % 2 == 1);
    return ans;
  }
};
