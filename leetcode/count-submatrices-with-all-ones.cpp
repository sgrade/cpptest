// 1504. Count Submatrices With All Ones
// https://leetcode.com/problems/count-submatrices-with-all-ones/

#include <vector>
#include <stack>
#include <tuple>


// Based on Editorial's Approach 2: Monotonic Stack
class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        std::vector<int> heights(cols, 0);
        int ans = 0;
        for (const auto& row : mat) {
            for (int c = 0; c < cols; ++c) {
                heights[c] = row[c] == 0 ? 0 : heights[c] + 1;
            }
            std::stack<std::tuple<int, int, int>> st;
            st.emplace(-1, 0, -1);
            for (int i = 0; i < cols; ++i) {
                int h = heights[i];
                while (std::get<2>(st.top()) >= h) {
                    st.pop();
                }
                auto& top = st.top();
                int j = std::get<0>(top), prev = std::get<1>(top), cur = prev + (i - j) * h;
                st.emplace(i, cur, h);
                ans += cur;
            }
        }
        return ans;
    }
};
