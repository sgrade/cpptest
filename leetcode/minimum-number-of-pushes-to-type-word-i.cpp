// 3014. Minimum Number of Pushes to Type Word I
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/

#include <string>

using namespace std;

class Solution {
 public:
  int minimumPushes(string word) {
    int ans = 0;
    for (size_t i = 0; i < word.size(); ++i) {
      ans += (i / 8 + 1);
    }
    return ans;
  }
};