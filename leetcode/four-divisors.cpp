// 1390. Four Divisors
// https://leetcode.com/problems/four-divisors/

#include <vector>

using namespace std;

// Based on
// https://leetcode.com/problems/four-divisors/solutions/7463933/b-ks-solutionjust-math-shortest-code-of-07gxj
class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int total_sum = 0;
    for (const int n : nums) {
      total_sum += GetSumOfFactors(n);
    }
    return total_sum;
  }

 private:
  int GetSumOfFactors(int n) {
    int cur_sum = 0;
    int factors = 0;
    for (int divisor1 = 2; divisor1 * divisor1 <= n; ++divisor1) {
      if (n % divisor1 == 0) {
        int divisor2 = n / divisor1;
        if (divisor2 == divisor1 || factors > 0) {
          return 0;
        }
        cur_sum = divisor1 + divisor2;
        ++factors;
      }
    }
    if (factors == 0) {
      return 0;
    }
    return 1 + cur_sum + n;
  }
};
