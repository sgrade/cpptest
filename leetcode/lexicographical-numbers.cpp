// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Iterative Approach
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> ans;
        int x = 1;
        for (int i = 0; i < n; ++i){
            ans.emplace_back(x);
            if (x * 10 <= n) {
                x *= 10;
                continue;
            }
            while (x % 10 == 9 || x >= n)
                x /= 10;
            x += 1;
        }
        return ans;
    }
};
