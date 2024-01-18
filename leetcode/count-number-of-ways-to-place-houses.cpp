// 2320. Count Number of Ways to Place Houses
// https://leetcode.com/problems/count-number-of-ways-to-place-houses/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> placed(n + 1), empty(n + 1);
        placed[1] = 1;
        empty[1] = 1;
        for (int i = 2; i <= n; ++i) {
            placed[i] = empty[i - 1];
            empty[i] = (placed[i - 1] + empty[i - 1]) % MOD;
        }
        long long ans = (placed[n] + empty[n]) % MOD;
        return ans * ans % MOD;
    }
private:
    long long MOD = 1e9 + 7;
};
