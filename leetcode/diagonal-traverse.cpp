// 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/

#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int rows = mat.size(), cols = mat[0].size(), total_elements = rows * cols, diag = 1;
        
        bool up_and_right = true;
        int r = 0, c = 0;
        int row_modifier, col_modifier;

        while (total_elements) {

            int diag_elements;
            if (diag <= min(rows, cols))
                diag_elements = diag;
            else if (diag > min(rows, cols) && diag <= max(rows, cols))
                diag_elements = min(rows, cols);
            else
                diag_elements = (max(rows, cols) + min(rows, cols)) - diag;
            
            int elements_placed = 0;
            while (true) {
                ans.emplace_back(mat[r][c]);
                ++elements_placed;
                if (elements_placed < diag_elements) {
                    r += row_modifier;
                    c += col_modifier;
                }
                else {
                    if (up_and_right) {
                        up_and_right = false;
                        if (c == cols - 1) ++r;
                        ++c;
                        c = min(c, cols - 1);
                        row_modifier = 1, col_modifier = -1;
                    }
                    else {
                        up_and_right = true;
                        if (r == rows - 1) ++c;
                        ++r;
                        r = min(r, rows - 1);
                        row_modifier = -1, col_modifier = 1;
                    }
                    total_elements -= elements_placed;
                    break;
                }
            }

            ++diag;
        }

        return ans;
    }
};
