// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Postorder DFS (Depth-First Search)
// https://leetcode.com/problems/course-schedule/solution/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        for (vector<int>& v: prerequisites) {
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> checked(numCourses);
        vector<bool> path(numCourses);
        
        for (int i = 0; i < numCourses; ++i) {
            if (isCyclic(i, adj, checked, path)) {
                return false;
            }
        }
        return true;
    }
    
    bool isCyclic(int& curCourse, map<int, vector<int>>& adj, vector<bool>& checked, vector<bool>& path) {
        
        // this course has been checked, so no cycle with it
        if (checked[curCourse]) return false;
        // found a marked course in the path - cycle
        if (path[curCourse]) return true;
        
        // the course is in the path
        path[curCourse] = true;
        
        bool ret = false;
        for (int& child: adj[curCourse]) {
            ret = isCyclic(child, adj, checked, path);
            if (ret) break;
        }
        
        // after visiting all children, we don't need it in the path
        path[curCourse] = false;
        
        // all the children in the downstream visited -> 
        // the course check is completed
        checked[curCourse] = true;
        
        return ret;
    }
};


int main() {
    return 0;
}