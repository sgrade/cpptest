// 846. Hand of Straights
// https://leetcode.com/problems/hand-of-straights/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> counter;
        for (const int& num: hand)
            ++counter[num];

        int groups = n / groupSize;
        for (int i = 0; i < groups; ++i) {
            int current = counter.begin()->first;
            for (int j = 0; j < groupSize; ++j) {
                if (counter.find(current) == counter.end())
                    return false;
                --counter[current];
                if (counter[current] == 0)
                    counter.erase(current);
                ++current;
            }
        }

        return true;
    }
};
