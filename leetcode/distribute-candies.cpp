// 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ulong n = candyType.size();
        unordered_set<int> types;
        for (const int& t: candyType)
            types.emplace(t);
        return min(n / 2, types.size());
    }
};
