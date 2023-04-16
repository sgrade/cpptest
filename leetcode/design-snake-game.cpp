// 353. Design Snake Game
// https://leetcode.com/problems/design-snake-game/

#include <bits/stdc++.h>

using namespace std;


class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        rows = height;
        cols = width;
        for (int i = 0; i < food.size(); ++i)
            this->food.emplace(food[i]);
        body.emplace_front(0, 0);
    }
    
    int move(string direction) {
        // Move head
        s_head_row += directions[direction].first;
        s_head_col += directions[direction].second;
        
        // Is head out of boundary?
        if (s_head_row < 0 || s_head_row == rows || s_head_col < 0 || s_head_col == cols)
            return -1;
        
        pair<int, int> new_head(s_head_row, s_head_col);
        
        // Snake eats food
        if (!food.empty() && s_head_row == food.front()[0] && s_head_col == food.front()[1]) {
            ans += 1;
            food.pop();
            body.emplace_front(new_head);
            return ans;
        }
         
        body.pop_back();        

        // Snake eats itself
        if (find(body.begin(), body.end(), new_head) != body.end())
            return -1;
        
        body.emplace_front(new_head);

        return ans;
    }

private:
    int ans = 0;
    int cols, rows;
    queue<vector<int>> food;
    deque<pair<int, int>> body;
    int s_head_row = 0, s_head_col = 0;
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
