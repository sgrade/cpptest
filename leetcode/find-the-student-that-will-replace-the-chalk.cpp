// 1894. Find the Student that Will Replace the Chalk
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        int complete_cycles = k / sum;
        if (complete_cycles > 0)
            k -= complete_cycles * sum;
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return -1;
    }
};
