// 2154. Keep Multiplying Found Values by Two
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& v1, vector<int>& v2) {
           if (v1[0] < v2[0]) {
             return true;
           } else if (v1[0] == v2[0]) {
             return v1[1] > v2[1];
           }
           return false;
         });

    vector<int> to_pick_from_interval(intervals.size(), 2);
    int min_len = 0;

    for (int i = intervals.size() - 1; i >= 0; --i) {
      int cur_start = intervals[i][0], to_pick = to_pick_from_interval[i];

      for (int point = cur_start; point < cur_start + to_pick; ++point) {
        for (int j = 0; j <= i; ++j) {
          int cur_end = intervals[j][1];
          if (to_pick_from_interval[j] && point <= cur_end) {
            to_pick_from_interval[j]--;
          }
        }
        min_len++;
      }
    }
    return min_len;
  }
};
