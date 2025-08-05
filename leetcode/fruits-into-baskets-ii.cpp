// 3477. Fruits Into Baskets II
// https://leetcode.com/problems/fruits-into-baskets-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0, n = baskets.size();
        for (const int quantity: fruits) {
            for (int i = 0; i < n; ++i) {
                if (quantity <= baskets[i]) {
                    baskets[i] = 0;
                    ++placed;
                    break;
                }
            }
        }
        return n - placed;
    }
};
