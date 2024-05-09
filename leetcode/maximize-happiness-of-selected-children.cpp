// 3075. Maximize Happiness of Selected Children
// https://leetcode.com/problems/maximize-happiness-of-selected-children/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(happiness.begin(), happiness.end());
        int i = happiness.size() - 1, d = 0, current;
        long long ans = 0;
        while (k--) {
            current = happiness[i] - d;
            if (current <= 0)
                break;
            ans += current;
            --i;
            ++d;
        }
        return ans;
    }
};
