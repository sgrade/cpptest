// 1052. Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        for (int i = 0; i < customers.size(); ++i)
            ans += customers[i] * (!grumpy[i]);

        int not_satisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i])
                not_satisfied += customers[i];
        }

        int left = 0, right, max_not_satisfied = not_satisfied;
        for (right = minutes; right < customers.size(); ++right) {
            if (grumpy[left])
                not_satisfied -= customers[left];
            ++left;
            if (grumpy[right])
                not_satisfied += customers[right];
            max_not_satisfied = max(max_not_satisfied, not_satisfied);
        }

        return ans + max_not_satisfied;
    }
};
