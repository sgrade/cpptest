// 2214. Minimum Health to Beat Game
// https://leetcode.com/problems/minimum-health-to-beat-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1;
        int max_element = 0;
        for (const int& el: damage) {
            ans += el;
            max_element = max(max_element, el);
        }
        return ans - (max_element > armor ? armor : max_element);
    }
};
