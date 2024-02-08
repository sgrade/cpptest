// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
// Based on Leetcode's Approach 4: Greedy + BFS (Breadth-First Search)

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 4: Greedy + BFS (Breadth-First Search)
class Solution {
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i)
            squares.emplace_back(i * i);
        
        deque<int> q;
        q.emplace_back(n);
        
        int level = 0;
        while (!q.empty()) {
            ++level;
            deque<int> next_q;
            
            for (const int &remainder: q) {
                for (const int square: squares) {
                    if (remainder == square)
                        return level;
                    else if (remainder < square)
                        break;
                    else
                        next_q.emplace_back(remainder - square);
                }
            }
            
            q = next_q;
        }
        
        return level;
    }
};
