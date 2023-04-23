// 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins/

#include <bits/stdc++.h>

using namespace std;


// Math Editorial
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2LL * n + 0.25) - 0.5);
    }
};
