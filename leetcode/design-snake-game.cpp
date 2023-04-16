// 353. Design Snake Game
// https://leetcode.com/problems/design-snake-game/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
// 79 / 446 testcases passed
class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        rows = height;
        cols = width;
        snake.resize(height, vector<string>(width));
        fd = food;
        f_row = food[0][0];
        f_col = food[0][1];
    }
    
    int move(string direction) {
        // Direction from the old head to new head (to be used later for tail moves)
        snake[s_head_row][s_head_col] = direction;

        // Move head
        s_head_row += directions[direction].first;
        s_head_col += directions[direction].second;
        
        // Is head out of boundary?
        if (s_head_row < 0 || s_head_row == rows || s_head_col < 0 || s_head_col == cols)
            return -1;
        
        // Head eats food
        // f_row = -1 when there is no more food
        if (f_row != - 1 && s_head_row == f_row && s_head_col == f_col) {
            ans += 1;
            if (++f_idx < fd.size()) {
                f_row = fd[f_idx][0];
                f_col = fd[f_idx][1];
                return ans;
            }
            else 
                f_row = -1;
        }

        // Tail moves
        string s_tail_direction = snake[s_tail_row][s_tail_col];
        snake[s_tail_row][s_tail_col] = "";
        s_tail_row += directions[s_tail_direction].first;
        s_tail_col += directions[s_tail_direction].second;

        // Is head on a cell occupied by snake's body?
        if (!snake[s_head_row][s_head_col].empty())
            return -1;
        
        return ans;
    }

private:
    int ans = 0;
    int cols, rows;
    vector<vector<int>> fd;
    vector<vector<string>> snake;
    int s_head_row = 0, s_head_col = 0, s_tail_row = 0, s_tail_col = 0;
    int f_idx = 0;
    int f_row, f_col;
    unordered_map<string, pair<int, int>> directions {
        {"U", {-1, 0}},
        {"D", {1, 0}},
        {"L", {0, -1}},
        {"R", {0, 1}},
    };
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
