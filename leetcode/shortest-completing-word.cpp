// 748. Shortest Completing Word
// https://leetcode.com/problems/shortest-completing-word/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> counter(26);
        int need = 0;
        for (char ch: licensePlate) {
            if (!isalpha(ch)) continue;
            ++counter[tolower(ch) - 'a'];
            ++need;
        }
        
        size_t mx_size = numeric_limits<size_t>::max();
        string ans;

        for (const string& word: words) {
            int current_need = need;
            vector<int> current_counter = counter;
            for (const char& ch: word) {
                int current = ch - 'a';
                if (current_counter[current] > 0) {
                    --current_counter[current];
                    --current_need;
                    if (current_need == 0) {
                        if (word.size() < mx_size) {
                            mx_size = word.size();
                            ans = word;
                        }
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
