// 3025. Find the Number of Ways to Place People I
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/

#include <vector>
#include <algorithm>
#include <climits>

using std::vector;


// Based on https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/solutions/7146299/same-as-the-hard-lc-3027-beats-100
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0, n = points.size();
        for (int i = 0; i < n - 1; ++i) {
            int max_y = INT_MAX, yi = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                const int yj = points[j][1];
                if (yj >= yi && yj < max_y) {
                    ++ans;
                    max_y = yj;
                }
            }
        }
        return ans;
    }
private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2){
        return (v1[0] == v2[0]) ? v1[1] < v2[1] : v1[0] > v2[0];
    }
};
