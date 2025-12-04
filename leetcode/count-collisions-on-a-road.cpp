// 2211. Count Collisions on a Road
// https://leetcode.com/problems/count-collisions-on-a-road/

#include <algorithm>
#include <string>

using std::string;

class Solution {
 public:
  int countCollisions(string directions) {
    size_t l = directions.find_first_not_of('L');
    size_t r = directions.find_last_not_of('R');
    if (l == string::npos) {
      return 0;
    }
    int s = count(directions.begin() + l, directions.begin() + r + 1, 'S');
    return (r - l + 1) - s;
  }
};
