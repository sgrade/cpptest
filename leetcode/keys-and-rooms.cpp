// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), count = 1; // Start with room 0 visited
        vector<bool> visited(n, false);
        stack<int> st;
        st.emplace(0);
        visited[0] = true;
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            for (int key : rooms[current]) {
                if (!visited[key]) {
                    visited[key] = true;
                    st.push(key);
                    ++count;
                }
            }
        }
        return count == n;
    }
};
