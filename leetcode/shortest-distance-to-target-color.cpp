// 1182. Shortest Distance to Target Color
// https://leetcode.com/problems/shortest-distance-to-target-color/

#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
using std::min;


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        vector<vector<int>> dist(n, vector<int>(4, INT_MAX));
        vector<int> closest(4, -1);
        // left to right
        for (int i = 0; i < n; ++i) {
            int current_color = colors[i];
            closest[current_color] = i;
            for (int color = 1; color < 4; ++color) {
                if (closest[color] != -1) {
                    dist[i][color] = i - closest[color];
                }
            }
        }
        // right to left
        closest.assign(4, -1);
        for (int i = n - 1; i >= 0; --i) {
            int current_color = colors[i];
            closest[current_color] = i;
            for (int color = 1; color < 4; ++color) {
                if (closest[color] != -1) {
                    dist[i][color] = min(dist[i][color], closest[color] - i);
                }
            }
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int current_ans = dist[queries[i][0]][queries[i][1]];
            ans[i] = current_ans == INT_MAX ? -1 : current_ans;
        }
        return ans;
    }
};
