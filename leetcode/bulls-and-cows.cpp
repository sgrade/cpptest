// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> counter_s;
        for (size_t i = 0; i < secret.size(); ++i) ++counter_s[secret[i]];
        
        int x = 0, y = 0;
        char ch;
        unordered_map<char, int> counter_g;
        for (size_t i = 0; i < guess.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++x;
                --counter_s[secret[i]];
            }
            else ++counter_g[guess[i]];
        }

        for (const auto& [ch, cnt]: counter_s) {
            y += min(max(0, cnt), counter_g[ch]);
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};
