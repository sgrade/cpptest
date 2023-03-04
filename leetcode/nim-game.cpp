// 292. Nim Game
// https://leetcode.com/problems/nim-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};
