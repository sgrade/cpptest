// 849. Maximize Distance to Closest Person
// https://leetcode.com/problems/maximize-distance-to-closest-person/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int n = seats.size();
        int ans = 1, current_ans;

        vector<int>::iterator leftmost_it = find(seats.begin(), seats.end(), 1);
        int leftmost_idx = distance(seats.begin(), leftmost_it);
        ans = max(ans, leftmost_idx);
        vector<int>::reverse_iterator rightmost_it = find(seats.rbegin(), seats.rend(), 1);
        int rightmost_idx = distance(seats.begin(), rightmost_it.base()) - 1;
        ans = max(ans, n - 1 - rightmost_idx);

        vector<int>::iterator left = leftmost_it, right;
        while (left < rightmost_it.base() - 1) {
            right = find(left + 1, seats.end(), 1);
            current_ans = distance(left, right) / 2;
            ans = max (ans, current_ans);
            left = right;
        }

        return ans;
    }
};
