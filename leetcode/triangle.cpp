// 120. Triangle
// https://leetcode.com/problems/triangle/

#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::min;
using std::min_element;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int level = 1; level < triangle.size(); ++level) {
            for (int i = 0; i <= level; ++i) {
                int prev_i_minus_one = i == 0 ? INT_MAX : triangle[level - 1][i - 1];
                int prev_i = i == level ? INT_MAX : triangle[level - 1][i];
                triangle[level][i] += min(prev_i_minus_one, prev_i);
            }
        }
        vector<int>& last_row = *triangle.rbegin();
        int min_path_sum = *min_element(last_row.begin(), last_row.end());
        return min_path_sum;
    }
};
