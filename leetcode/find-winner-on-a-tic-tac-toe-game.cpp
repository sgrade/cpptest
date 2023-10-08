// 1275. Find Winner on a Tic Tac Toe Game
// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3));
        for (int i = 0; i < moves.size(); ++i) {
            int row = moves[i][0], col = moves[i][1];
            if (i % 2 == 0)
                board[row][col] = 'A';
            else
                board[row][col] = 'B';
        }

        for (int row = 0; row < 3; ++row) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == 'A')
                    return "A";
                else if (board[row][0] == 'B')
                    return "B";
            }
        }

        for (int col = 0; col < 3; ++col) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 'A')
                    return "A";
                else if (board[0][col] == 'B')
                    return "B";
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[2][0] == board[1][1] && board[1][1] == board[0][2])
            ) {
            if (board[1][1] == 'A')
                return "A";
            else if (board[1][1] == 'B')
                return "B";
        }

        if (moves.size() == 9)
            return "Draw";
        return "Pending";
    }
};
