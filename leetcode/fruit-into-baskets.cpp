// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int left = 0, right = 0;
        int n = fruits.size();
        map<int, int> types;
        for (; right < n; ++right) {
            ++types[fruits[right]];
            while (types.size() > 2 && left < right) {
                --types[fruits[left]];
                if (types[fruits[left]] == 0) {
                    types.erase(fruits[left]);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
