// 656. Coin Path
// https://leetcode.com/problems/coin-path/

#include <vector>
#include <climits>

using std::vector;


// Based on Editorial's Approach #2 Using Memoization
class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        n = coins.size();
        memo.resize(n);
        vector<int> next(n, -1);

        jump(coins, maxJump, 0, next);
        
        vector<int> ans;
        int i;
        for (i = 0; i < n && next[i] > 0; i = next[i]) {
            ans.emplace_back(i + 1);
        }
        if (i == coins.size() - 1 && coins[i] >= 0) {
            ans.emplace_back(coins.size());
        } else {
            return {};
        }
        return ans;
    }

private:
    int n;
    vector<long long> memo;
    long long jump(const vector<int>& coins, int maxJump, int i, vector<int>& next) {
        if (memo[i] > 0) {
            return memo[i];
        }
        if (i == n - 1 && coins[i] >= 0) {
            return coins[i];
        }
        long long min_cost = INT_MAX;
        for (int j = i + 1; j <= i + maxJump && j < n; ++j) {
            if (coins[j] >= 0) {
                long long cost = coins[i] + jump(coins, maxJump, j, next);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        memo[i] = min_cost;
        return min_cost;
    }
};
