// 3342. Find Minimum Time to Reach Last Room II
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Shortest Path + Dijkstra
class State {
    public:
        int r, c, time;
        State(int r, int c, int time) : r(r), c(c), time(time){}
    };

    class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            rows = moveTime.size(), cols = moveTime[0].size();
            visited.resize(rows, vector<bool>(cols));
            times.resize(rows, vector<int>(cols, INT_MAX));
            times[0][0] = 0;

            auto cmp = [](const State& st1, const State& st2) {
                return st1.time > st2.time;
            };
            priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
            pq.emplace(0, 0, 0);

            while (!pq.empty()) {
                State st = pq.top();
                pq.pop();
                if (visited[st.r][st.c])
                    continue;
                if (st.r == rows - 1 && st.c == cols - 1)
                    break;

                visited[st.r][st.c] = 1;
                for (const auto& [r_diff, c_diff]: directions) {
                    int r = st.r + r_diff, c = st.c + c_diff;
                    if (r < 0 || r >= rows || c < 0 || c >= cols)
                        continue;
                    int time = max(times[st.r][st.c], moveTime[r][c]) + (st.r + st.c) % 2 + 1;
                    if (times[r][c] > time) {
                        times[r][c] = time;
                        pq.emplace(r, c, time);
                    }
                }
            }

            return times[rows - 1][cols - 1];
        }

    private:
        int rows, cols;
        vector<vector<bool>> visited;
        vector<vector<int>> times;
        vector<pair<int, int>> directions {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
    };
