// 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(people.begin(), people.end());
        int n = people.size(), left = 0, right = n - 1;
        int ans = 0;
        while (left <= right) {
            if (people[left] + people[right--] <= limit)
                ++left;
            ++ans;
        }
        return ans;
    }
};
