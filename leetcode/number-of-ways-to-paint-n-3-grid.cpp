// 1411. Number of Ways to Paint N × 3 Grid
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

// Based on
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/solutions/7460522/clean-code-time-on-space-o1-explained-by-fgmb
class Solution {
 public:
  int numOfWays(int n) {
    constexpr int kMod = 1e9 + 7;

    // Patterns using 2 colors (e.g., ABA, ACA, BAB):  3 choices for first, 2
    // for second, 1 for third = 6
    long long two_colors = 6;

    // Patterns using all 3 colors (e.g., ABC, ACB, BAC)
    // 3 * 2 * 1 = 6
    long long three_colors = 6;

    for (int i = 2; i <= n; ++i) {
      // From a two-color pattern: 2 ways to create a new two-color pattern
      // From a three-color pattern: 2 ways to create a new two-color pattern
      long long next_two_colors = (2 * two_colors + 2 * three_colors) % kMod;
      // From a two-color pattern: 2 ways to create a new three-color pattern
      // From a three-color pattern: 3 ways to create a new three-color pattern
      long long next_three_colors = (2 * two_colors + 3 * three_colors) % kMod;
      two_colors = next_two_colors;
      three_colors = next_three_colors;
    }
    return (two_colors + three_colors) % kMod;
  }
};
