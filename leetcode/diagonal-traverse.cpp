
// 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> ans;
        for (int d = 0; d < rows + cols - 1; ++d) {
            vector<int> diagonal;
            int r = d < cols ? 0 : d - cols + 1;
            int c = d < cols ? d : cols - 1;
            while (r < rows && c >= 0) {
                diagonal.emplace_back(mat[r][c]);
                ++r;
                --c;
            }
            if (d % 2 == 0) {
                std::reverse(diagonal.begin(), diagonal.end());
            }
            ans.insert(ans.end(), diagonal.begin(), diagonal.end());
        }
        return ans;
    }
};

