// 1921. Eliminate Maximum Number of Monsters
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> time(n);
        for (int i = 0; i < n; ++i)
            time[i] = (float)dist[i] / speed[i];
        sort(time.begin(), time.end());
        for (int i = 1; i < n; ++i) {
            if (time[i] <= i)
                return i;
        }
        return n;
    }
};
