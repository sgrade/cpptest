// 277. Find the Celebrity
// https://leetcode.com/problems/find-the-celebrity/

#include <bits/stdc++.h>

using namespace std;


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int celebrity_candidate = 0;
        bool current;
        for (int i = 0; i < n; ++i) {
            if (knowsWithCache(celebrity_candidate, i))
                celebrity_candidate = i;
        }
        if (isCelebrity(celebrity_candidate, n))
            return celebrity_candidate;
        return -1;
    }

private:
    map<pair<int, int>, bool> cache;

    bool knowsWithCache (const int &a, const int &b) {
        pair<int, int> p = {a, b};
        if (cache.find(p) == cache.end())
            cache[p] = knows(a, b);
        return cache[p];
    }

    bool isCelebrity (const int &candidate_celebrity, const int &n) {
        for (int i = 0; i < n; ++i) {
            if (i == candidate_celebrity)
                continue;
            if (knowsWithCache(candidate_celebrity, i) || !knowsWithCache(i, candidate_celebrity))
                return false;
        }
        return true;
    }

    // Mock to imitate the API
    bool knows(int a, int b) {
        return true;
    }
};
