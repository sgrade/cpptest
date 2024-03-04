// 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, n = tokens.size(), left = 0, right = n - 1;
        while (left <= right) {
            if (power < tokens[left]) {
                if (score <= 0)
                    return 0;
                if (left == right)
                    return score;
                power += tokens[right--];
                --score;
                continue;
            }
            power -= tokens[left++];
            ++score;
        }
        return score;
    }
};
