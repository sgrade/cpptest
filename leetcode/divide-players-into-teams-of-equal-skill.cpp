// 2491. Divide Players Into Teams of Equal Skill
// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(skill.begin(), skill.end());
        int left = 0, right = skill.size() - 1;
        long long ans = 0;
        int sum = skill[left] + skill[right], current_sum;
        while (left < right) {
            current_sum = skill[left] + skill[right];
            if (current_sum != sum)
                return -1;
            ans += skill[left] * skill[right];
            ++left;
            --right;
        }
        return ans;
    }
};
