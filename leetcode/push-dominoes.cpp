// 838. Push Dominoes
// https://leetcode.com/problems/push-dominoes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2: Calculate Force
class Solution {
    public:
        string pushDominoes(string dominoes) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = dominoes.size();
            vector<int> forces(n);

            int force = 0;
            for (int i = 0; i < n; ++i) {
                if (dominoes[i] == 'R')
                    force = n;
                else if (dominoes[i] == 'L')
                    force = 0;
                else
                    force = max(force - 1, 0);
                forces[i] = force;
            }

            force = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (dominoes[i] == 'L')
                    force = n;
                else if (dominoes[i] == 'R')
                    force = 0;
                else
                    force = max(force - 1, 0);
                forces[i] -= force;
            }

            string ans;
            for (const int& f: forces) {
                if (f > 0)
                    ans += 'R';
                else if (f < 0)
                    ans += 'L';
                else
                    ans += '.';
            }
            return ans;
        }
    };
