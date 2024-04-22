// 752. Open the Lock
// https://leetcode.com/problems/open-the-lock/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Breadth-First Search
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> next_slot = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'}
        };
        unordered_map<char, char> prev_slot = {
            {'0', '9'},
            {'1', '0'},
            {'2', '1'},
            {'3', '2'},
            {'4', '3'},
            {'5', '4'},
            {'6', '5'},
            {'7', '6'},
            {'8', '7'},
            {'9', '8'}
        };

        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end())
            return -1;

        int ans = 0;
        queue<string> pending;
        pending.emplace("0000");

        while (!pending.empty()) {
            int n = pending.size();
            while (n--) {
                string current = pending.front();
                pending.pop();
                if (current == target)
                    return ans;

                for (int i = 0; i < 4; ++i) {
                    string next = current;
                    next[i] = next_slot[next[i]];
                    if (visited.find(next) == visited.end()) {
                        pending.emplace(next);
                        visited.emplace(next);
                    }

                    next = current;
                    next[i] = prev_slot[next[i]];
                    if (visited.find(next) == visited.end()) {
                        pending.emplace(next);
                        visited.emplace(next);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
