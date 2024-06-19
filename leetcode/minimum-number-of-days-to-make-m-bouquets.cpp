// 1482. Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Binary Search
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        auto p = minmax_element(bloomDay.begin(), bloomDay.end());
        int min_day = *(p.first), max_day = *(p.second), ans = -1;
        while (min_day <= max_day) {
            int current_day = min_day + (max_day - min_day) / 2;
            int bouquets_made = getBouquetsReadyByDay (current_day, bloomDay, k);
            if (bouquets_made >= m) {
                max_day = current_day - 1;
                ans = current_day;
            }
            else
                min_day = current_day + 1;
        }
        return ans;
    }

private:
    int n;
    int getBouquetsReadyByDay (const int& day, vector<int>& bloomDay, int& k) {
        int bouquets = 0, flowers = 0, mx;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] > day) {
                flowers = 0;
                continue;
            }
            if (++flowers == k) {
                ++bouquets;
                flowers = 0;
                continue;
            }
        }
        return bouquets;
    }
};
