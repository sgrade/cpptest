// 1652. Defuse the Bomb
// https://leetcode.com/problems/defuse-the-bomb/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        ios::sync_with_stdio(false);

        int n = code.size();
        vector<int> ans;

        if (k == 0)
            return vector<int>(n);

        bool rev = k < 0 ? true : false;
        k = abs(k);

        if (rev)
            reverse (code.begin(), code.end());

        code.insert(code.end(), code.begin(), code.begin() + k);
        for (int i = 0; i < n; ++i)
            code[i] = accumulate(code.begin() + i + 1, code.begin() + i + 1 + k, 0);
        code.erase(code.begin() + n, code.end());

        if (rev)
            reverse (code.begin(), code.end());

        return code;
    }
};
