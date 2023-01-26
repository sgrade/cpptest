// 2359. Find Closest Node to Given Two Nodes
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Breadth First Search
// Optimized the iteration: 
// queue is not needed as there is only one neighbor (next_node)
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int min_dist = numeric_limits<int>::max(), current_dist;
        int min_dist_node = -1;
        for (int current_node = 0; current_node < n; ++current_node) {
            current_dist = max(dist1[current_node], dist2[current_node]);
            if (current_dist < min_dist) {
                min_dist_node = current_node;
                min_dist = current_dist;
            }
        }

        return min_dist_node;
    }

private:
    int n;
    void bfs(const int& start_node, const vector<int>& edges, vector<int>& dist) {
        vector<bool> visited(n);
        dist[start_node] = 0;
        visited[start_node] = true;

        int current_node = start_node, next_node = edges[current_node];
        while (next_node != -1 && !visited[next_node]) {
            dist[next_node] = dist[current_node] + 1;
            visited[next_node] = true;
            current_node = next_node;
            next_node = edges[current_node];
        }
    }
};
