// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <unordered_map>
#include  <vector>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {       
        // Checking rows and columns
        unordered_map<int, vector<bool>> rows;
        unordered_map<int, vector<bool>> columns;
        for (int i = 0; i < 9; ++i) 
            rows[i] = vector<bool>(10);
        for (int j = 0; j < 9; ++j)
            columns[j] = vector<bool>(10);
        int x;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') 
                    continue;
                x = board[i][j] - '0';
                if (rows[i][x] || columns[j][x]) {
                    return false;
                }
                rows[i][x] = true;
                columns[j][x] = true;
            }
        }
               
        // Checking 3x3
        for (int k = 0; k < 9; k +=3) {
            for (int l = 0; l < 9; l +=3) {
                if (!check_3x3(board, k, l)) 
                    return false;
            }
        }
        
        return true;
    }
    
    bool check_3x3 (vector<vector<char>> &board, int &k, int &l) {
        int x;
        vector<bool> sub_box(10);
        for (int i = k; i < k + 3; ++i) {
            for (int j = l; j < l + 3; ++j) {
                if (board[i][j] == '.') 
                    continue;
                x = board[i][j] - '0';
                if (sub_box[x]) 
                    return false;
                sub_box[x] = true;
            }
        }
        return true;
    }
};
