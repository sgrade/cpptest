// 605. Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        size_t len = flowerbed.size();
        if (len == 1) {
            if (flowerbed[0] == 0) return true;
            else return false;
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            --n;
        }
        if (len > 2 && flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0) {
            flowerbed[len - 1] = 1;
            --n;
        }
        for (size_t i = 1; n > 0 && i < len - 1; ++i) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return !(n > 0);
    }
};
