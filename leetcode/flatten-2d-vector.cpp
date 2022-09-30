// 251. Flatten 2D Vector
// https://leetcode.com/problems/flatten-2d-vector/

#include <bits/stdc++.h>

using namespace std;


class Vector2D {
public:
    vector<int> flattened;
    int idx = 0;
    int n;
    Vector2D(vector<vector<int>>& vec) {
        for (const vector<int> &v: vec) {
            for (int i = 0; i < v.size(); ++i) {
                flattened.emplace_back(v[i]);
            }
        }
        idx = 0;
        n = flattened.size();
    }
    
    int next() {
        return flattened[idx++];
    }
    
    bool hasNext() {
        if (idx < n) {
            return true;
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
