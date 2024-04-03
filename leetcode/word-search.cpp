// 79. Word Search
// https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int rows = board.size();
        int columns = board[0].size();
        int ans = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ans = explore(board, word, i, j, 0);
                if (ans)
                    return true;
            }
        }
        return false;
    }

    bool explore(vector<vector<char>>& board, const string& word, const int& r, const int& c, int idx) {
        if (idx >= word.size())
            return true;
        if (r < 0 || r > board.size() - 1 || c < 0 || c > board[0].size() - 1)
            return false;
        if (board[r][c] != word[idx])
            return false;

        // The same letter cell may not be used more than once.
        board[r][c] = '#';

        // Return without cleanup
        if (explore(board, word, r - 1, c, idx + 1))
            return true;
        if (explore(board, word, r + 1, c, idx + 1))
            return true;
        if (explore(board, word, r, c - 1, idx + 1))
            return true;
        if (explore(board, word, r, c + 1, idx + 1))
            return true;

        // Cleanup
        board[r][c] = word[idx];

        return false;
    }
};
