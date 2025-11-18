// 717. 1-bit and 2-bit Characters
// https://leetcode.com/problems/1-bit-and-2-bit-characters/

#include <vector>

using std::vector;

// Based on Editorial's Approach 2: Greedy
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    int ones = 0;
    for (int i = bits.size() - 2; i >= 0; --i) {
      if (bits[i] == 1) {
        ++ones;
      } else {
        break;
      }
    }
    return ones % 2 == 0;
  }
};
