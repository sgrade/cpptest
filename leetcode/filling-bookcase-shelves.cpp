// 1105. Filling Bookcase Shelves
// https://leetcode.com/problems/filling-bookcase-shelves/

#include <bits/stdc++.h>

using namespace std


// Based on https://leetcode.com/problems/filling-bookcase-shelves/solutions/5561109/pure-dp-code-98-margin-no-memoization-followed/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        ios::sync_with_stdio(false);

        cin.tie(nullptr);
        int n = books.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            // Place current book on the shelf
            dp[i] = dp[i - 1] + h;
            // Place current book on the previous shelf
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth)
                    break;
                h = max (h, books[j - 1][1]);
                dp[i] = min (dp[i], dp[j - 1] + h);
            }
        }
        return dp[n];
    }
};
