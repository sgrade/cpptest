// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
        }
        
        map<vector<int>, int> mp;
        for (int i = 0; i < dominoes.size(); ++i) {
            ++mp[dominoes[i]];
        }
        
        long long ans = 0;
        for (auto &p: mp) {
            if (p.second > 1) {
                int c = 0;
                while(--p.second) {
                    c += p.second;
                }
                ans += c;
            }
        }
        
        return ans;
    }
};
