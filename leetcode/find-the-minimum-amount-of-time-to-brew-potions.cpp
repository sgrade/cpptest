// 3494. Find the Minimum Amount of Time to Brew Potions
// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/

#include <vector>

using std::vector;
using std::max;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int ns = skill.size(), nm = mana.size();
        vector<long long> times(ns);
        for (int im = 0; im < nm; ++im) {
            long long cur_time = 0;
            for (int is = 0; is < ns; ++is) {
                cur_time = max(cur_time, times[is]) + skill[is] * mana[im];
            }
            times[ns - 1] = cur_time;
            for (int is = ns - 2; is >= 0; --is) {
                times[is] = times[is + 1] - skill[is + 1] * mana[im];
            }
        }
        return times[ns - 1];
    }
};
