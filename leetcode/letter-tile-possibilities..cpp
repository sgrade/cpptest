// 1079. Letter Tile Possibilities
// https://leetcode.com/problems/letter-tile-possibilities/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Permutations and Combinations
class Solution {
public:
    int numTilePossibilities(string tiles) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(tiles.begin(), tiles.end());
        return getSequences(tiles, "", 0) - 1;
    }

private:
    unordered_set<string> seen;

    int getPermutations (string& s) {
        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'A'];
        int total = tgamma(s.size() + 1);   // factorial
        for (int count: counter) {
            if (count > 1) {
                int factorial = tgamma(count + 1);
                total /= factorial;
            }
        }
        return total;
    }

    int getSequences(string& tiles, string current, int pos) {
        if (pos >= tiles.size()) {
            if (seen.emplace(current).second)
                return getPermutations(current);
            return 0;
        }

        return  getSequences(tiles, current, pos + 1) + 
                getSequences(tiles, current + tiles[pos], pos + 1);
    }
};
