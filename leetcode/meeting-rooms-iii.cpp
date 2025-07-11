// 2402. Meeting Rooms III
// https://leetcode.com/problems/meeting-rooms-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sorting, Counting using Priority Queues
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> meetings_in_room(n); // meetings in the rooms
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used_rooms;
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; ++i)
            free_rooms.emplace(i);
        sort(meetings.begin(), meetings.end());

        for (const vector<int>& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            while (!used_rooms.empty() && used_rooms.top().first <= start) {
                int room = used_rooms.top().second;
                used_rooms.pop();
                free_rooms.emplace(room);
            }
            if (!free_rooms.empty()) {
                int room = free_rooms.top();
                free_rooms.pop();
                used_rooms.emplace(end, room);
                ++meetings_in_room[room];
            }
            else {
                auto [time, room] = used_rooms.top();
                used_rooms.pop();
                used_rooms.emplace(time + end - start, room);
                ++meetings_in_room[room];
            }
        }

        int max_meetings = 0, room = 0;
        for (int i = 0; i < n; ++i) {
            if (meetings_in_room[i] > max_meetings) {
                max_meetings = meetings_in_room[i];
                room = i;
            }
        }
        return room;
    }
};
