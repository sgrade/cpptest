// 1198. Find Smallest Common Element in All Rows
// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/


#include <vector>
#include <algorithm>


// Based on Editorial's Approach 3: Row Positions
class Solution {
 public:
    int smallestCommonElement(std::vector<std::vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();
        std::vector<int> idx(rows, 0);
        while (true) {
            int candidate = mat[0][idx[0]];
            bool all_match = true;
            for (int r = 1; r < rows; ++r) {
                while (idx[r] < cols && mat[r][idx[r]] < candidate) {
                    ++idx[r];
                }
                if (idx[r] == cols) {
                    return -1;
                }
                if (mat[r][idx[r]] != candidate) {
                    candidate = std::max(candidate, mat[r][idx[r]]);
                    all_match = false;
                }
            }
            if (all_match) return candidate;
            for (int r = 0; r < rows; ++r) {
                while (idx[r] < cols && mat[r][idx[r]] < candidate) {
                    ++idx[r];
                }
                if (idx[r] == cols) {
                    return -1;
                }
            }
        }
        return -1;
    }
};
