// 3307. Find the K-th Character in String Game II
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/solutions/6916406/beginner-freindly-java-c-python-js
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int shift = 0;
        vector<long long> lengths;
        long long len = 1;
        for (const int& op: operations) {
            len *= 2;
            lengths.emplace_back(len);
            if (len >= k)
                break;
        }
        for (int i = lengths.size() - 1; i >= 0; --i) {
            long long half = lengths[i] / 2;
            if (k > half) {
                k -= half;
                if (operations[i])
                    ++shift;
            }
        }
        char ans = 'a' + shift % 26;
        return ans;
    }
};
