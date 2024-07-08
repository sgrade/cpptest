// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> friends;
        for (int i = n; i > 0; --i)
            friends.emplace_front(i);
        auto it = friends.begin();
        while (--n) {
            int cnt = 1;
            while (cnt++ < k) {
                ++it;
                if (it == friends.end())
                    it = friends.begin();
            }
            friends.erase(it++);
            if (it == friends.end())
                    it = friends.begin();
        }
        return *friends.begin();
    }
};
