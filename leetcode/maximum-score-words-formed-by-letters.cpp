// 1255. Maximum Score Words Formed by Letters
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Backtracking
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        freq.resize(26, 0);
        sub_letters.resize(26, 0);
        for (const char& c: letters)
            ++freq[c - 'a'];
        backtrack(n - 1, words, score, 0);
        return ans;
    }
private:
    int n;
    int ans = 0;
    vector<int> freq, sub_letters;

    void backtrack (int idx, const vector<string>& words, const vector<int>& score, int current_ans) {
        if (idx == -1) {
            ans = max(ans, current_ans);
            return;
        }

        backtrack(idx - 1, words, score, current_ans);

        for (const char& ch: words[idx]) {
            int i = ch - 'a';
            ++sub_letters[i];
            current_ans += score[i];
        }

        if (isValidWord())
            backtrack(idx - 1, words, score, current_ans);

        for (const char& ch: words[idx]) {
            int i = ch - 'a';
            --sub_letters[i];
            current_ans -= score[i];
        }
    }

    bool isValidWord () {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] < sub_letters[i])
                return false;
        }
        return true;
    }
};
