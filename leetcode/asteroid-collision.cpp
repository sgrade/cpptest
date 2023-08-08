// 735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        list<int> lst (asteroids.begin(), asteroids.end());
        lst.emplace_front(0);
        list<int>::iterator left_it = lst.begin(), right_it = lst.begin();
        ++left_it;
        ++right_it;
        ++right_it;
        int left, right, abs_left, abs_right;

        while (right_it != lst.end()) {
            left = *left_it;
            right = *right_it;
            abs_left = abs(left);
            abs_right = abs(right);
            
            if (left > 0 && right < 0) {
                if (abs_left == abs_right) {
                    lst.erase(left_it--);
                    lst.erase(right_it++);
                }
                else if (abs_left > abs_right) {
                    lst.erase(right_it++);
                }
                else {
                    lst.erase(left_it--);
                }
            }
            else {
                ++right_it;
                ++left_it;
                continue;
            }

            if (left_it == lst.begin()) {
                ++left_it;
                right_it = left_it;
                ++right_it;
            }
        }

        left_it = lst.begin();
        ++left_it;
        return vector<int>(left_it, lst.end());
    }
};
