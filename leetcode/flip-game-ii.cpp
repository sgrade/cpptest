// 294. Flip Game II
// https://leetcode.com/problems/flip-game-ii/

#include <bits/stdc++.h>

using namespace std;


// Key ideas are based on https://leetcode.com/problems/flip-game-ii/solutions/73960/neat-c-code-with-dfs/
// SLOW
class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        if (n == 0) return false;

        bool has_moved = false;
        for (int i = 0; i < n - 1; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                currentState[i] = '-';
                currentState[i + 1] = '-';
                has_moved = true;
                if (!canWin(currentState)) return true;
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        return false;
    }
};
