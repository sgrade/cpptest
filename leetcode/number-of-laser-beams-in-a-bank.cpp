// 2125. Number of Laser Beams in a Bank
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev, cur;
        prev = count(bank[0].begin(), bank[0].end(), '1');
        for (int i = 1; i < bank.size(); ++i) {
            cur = count(bank[i].begin(), bank[i].end(), '1');
            if (cur != 0) {
                ans += prev * cur;
                prev = cur;
            }
        }
        return ans;
    }
};
