// 1518. Water Bottles
// https://leetcode.com/problems/water-bottles/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottles = 0;
        while (numBottles) {
            ans += numBottles;
            emptyBottles = numBottles + emptyBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        }
        return ans;
    }
};
