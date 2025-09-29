// 1039. Minimum Score Triangulation of Polygon
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <vector>
#include <unordered_map>
#include <climits>

using std::vector;
using std::unordered_map;
using std::min;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        return dp(0, n - 1, values);
    }
private:
    int n;
    unordered_map<int, int> memo;
    int dp (const int i, const int j, vector<int>& values) {
        if (i + 2 > j) {
            return 0;
        }
        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }
        int key = i * n + j;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int min_score = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            min_score = min (min_score, 
                values[i] * values[k] * values[j] + dp(i, k, values) + dp(k, j, values))
            ;
        }
        return memo[key] = min_score;
    }
};
