// 735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        bool current_asteroid_exlpodes;
        for (const int& asteroid: asteroids) {
            current_asteroid_exlpodes = false;
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }
                current_asteroid_exlpodes = true;
                break;
            }
            if (!current_asteroid_exlpodes)
                st.emplace(asteroid);
        }
        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};
