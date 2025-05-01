// 2071. Maximum Number of Tasks You Can Assign
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Binary Search + Greedy Selection of Workers
class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            sort(workers.begin(), workers.end()),
            sort(tasks.begin(), tasks.end());
            t = tasks.size(), w = workers.size(), this->pills = pills, this->strength = strength;

            int left = 1, right = min(t, w), ans = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (check(mid, tasks, workers)) {
                    ans = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            return ans;
        }

    private:
        int t, w, pills, strength;

        bool check (int mid, vector<int>& tasks, vector<int>& workers) {
            int p = pills;
            deque<int> dq;
            int worker = w - 1;
            for (int i = mid - 1; i >= 0; --i) {
                while (worker >= w - mid && workers[worker] + strength >= tasks[i])
                    dq.emplace_front(workers[worker--]);
                if (dq.empty())
                    return false;
                else if (dq.back() >= tasks[i])
                    dq.pop_back();
                else {
                    if (!p)
                        return false;
                    --p;
                    dq.pop_front();
                }
            }
            return true;
        }
    };
