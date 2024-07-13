// 2751. Robot Collisions
// https://leetcode.com/problems/robot-collisions/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sorting & Stack
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = positions.size();
        vector<int> sorted(n);
        iota (sorted.begin(), sorted.end(), 0);
        sort (sorted.begin(), sorted.end(), 
            [&](const int& left, const int& right) {
                return positions[left] < positions[right];
            }
        );

        stack<int> st;
        for (const int& current: sorted) {
            if (directions[current] == 'R') {
                st.emplace(current);
                continue;
            }

            while (!st.empty() && healths[current] > 0) {
                int colliding = st.top();

                if (healths[current] > healths[colliding]) {
                    --healths[current];
                    healths[colliding] = 0;
                    st.pop();
                }
                else if (healths[current] < healths[colliding]) {
                    healths[current] = 0;
                    --healths[colliding];
                }
                else {
                    healths[current] = 0;
                    healths[colliding] = 0;
                    st.pop();
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0)
                ans.emplace_back(healths[i]);
        }
        return ans;
    }
};
