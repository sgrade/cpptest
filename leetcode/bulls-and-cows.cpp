// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

#include <bits/stdc++.h>

using namespace std;


// VERY SLOW
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, unordered_set<int>> counter_s;
        for (size_t i = 0; i < secret.size(); ++i) counter_s[secret[i]].emplace(i);
        
        int x = 0, y = 0;
        char ch;
        unordered_map<char, int> counter_g; 
        for (size_t i = 0; i < guess.size(); ++i) {
            ch = guess[i];
            if (counter_s.find(ch) != counter_s.end()) {
                if (counter_s[ch].find(i) != counter_s[ch].end()) {
                    ++x;
                    counter_s[ch].erase(i);
                    continue;
                }
                ++counter_g[ch];
            }
        }

        for (const auto& [ch, cnt]: counter_s) {
            if (counter_g.find(ch) != counter_g.end()) {
                y += min((int)counter_s[ch].size(), counter_g[ch]);
            }
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};
