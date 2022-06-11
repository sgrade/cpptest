// 348. Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/

#include <bits/stdc++.h>

using namespace std;


class TicTacToe {
private:
    int n_;
    vector<int> rows, cols;
    int diag, anti_diag;
    
public:
    TicTacToe(int n) {
        n_ = n;
        rows.assign(n, 0);
        cols.assign(n, 0);
        diag = 0;
        anti_diag = 0;
    }
    
    int move(int row, int col, int player) {
        int score = (player == 1 ? 1 : -1);
        rows[row] += score;
        cols[col] += score;
        if (row == col) diag += score;
        if (row == n_ - col - 1) anti_diag += score;

        if (abs(rows[row]) == n_ ||
            abs(cols[col]) == n_ ||
            abs(diag) == n_ ||
            abs(anti_diag) == n_) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */


int main() {

    return 0;
}