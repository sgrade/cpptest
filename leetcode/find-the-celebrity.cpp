// 277. Find the Celebrity
// https://leetcode.com/problems/find-the-celebrity/

#include <bits/stdc++.h>

using namespace std;


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celebrity_candidate = 0;
        bool current;
        for (int i = 0; i < n; ++i) {
            if (KnowsWithCache(celebrity_candidate, i)) {
                celebrity_candidate = i;
            }
        }
        if (IsCelebrity(celebrity_candidate, n)) {
            return celebrity_candidate;
        }
        return -1;
    }
    
private:
    map<pair<int, int>, bool> cache;
    
    bool KnowsWithCache (const int &a, const int &b) {
        pair<int, int> p = {a, b};
        if (cache.find(p) == cache.end()) {
            cache[p] = knows(a, b);
        }
        return cache[p];
    }
    
    bool IsCelebrity (const int &candidate_celebrity, const int &n) {
        for (int i = 0; i < n; ++i) {
            if (i == candidate_celebrity)
                continue;
            if (KnowsWithCache(candidate_celebrity, i) || !KnowsWithCache(i, candidate_celebrity)) {
                return false;
            }
        }
        return true;
    }

    // Mock to imitate the API
    bool knows(int a, int b) {
        return true;
    }
};
