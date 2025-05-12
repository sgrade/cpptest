// 2094. Finding 3-Digit Even Numbers
// https://leetcode.com/problems/finding-3-digit-even-numbers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = digits.size();
        sort(digits.begin(), digits.end());

        unordered_set<int> st;
        int i = distance(digits.begin(), find_if_not(digits.begin(), digits.end(), [](int x){return x == 0;}));
        for (; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (digits[k] % 2 != 0 || i == k || j == k)
                        continue;
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    st.emplace(x);
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
};
