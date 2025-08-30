// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <vector>

using std::vector;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        rows = board.size(), cols = board[0].size();
        if (!isValid9x9(board, 0, 0, 9)) {
            return false;
        }
        for (int r_start = 0; r_start < 9; r_start += 3) {
            for (int c_start = 0; c_start < 9; c_start += 3) {
                if (!isValid3x3(board, r_start, c_start, 3)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int rows, cols;
    vector<bool> visited;

    bool isValid9x9 (vector<vector<char>>& board, int r_start, int c_start, int len) {
        for (int r = r_start; r < r_start + len; ++r) {
            visited.assign(10, false);
            for (int c = c_start; c < c_start + len; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int num = board[r][c] - '0';
                if (visited[num]) {
                    return false;
                }
                visited[num] = true;
            }
        }
        for (int c = c_start; c < c_start + len; ++c) {
            visited.assign(len + 1, false);
            for (int r = r_start; r < r_start + len; ++r) {
                if (board[r][c] == '.') {
                    continue;
                }
                int num = board[r][c] - '0';
                if (visited[num]) {
                    return false;
                }
                visited[num] = true;
            }
        }
        return true;
    }

    bool isValid3x3 (vector<vector<char>>& board, int r_start, int c_start, int len) {
        visited.assign(10, false);
        for (int r = r_start; r < r_start + len; ++r) {
            for (int c = c_start; c < c_start + len; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int num = board[r][c] - '0';
                if (visited[num]) {
                    return false;
                }
                visited[num] = true;
            }
        }
        return true;
    }
};
