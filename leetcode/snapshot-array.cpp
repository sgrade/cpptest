// 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/

#include <bits/stdc++.h>

using namespace std;


class SnapshotArray {
public:
    SnapshotArray(int length) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        snap_ar.resize(length, vector<pair<int, int>>(1));
    }
    
    void set(int index, int val) {
        vector<pair<int, int>>& snapshots = snap_ar[index];
        int prev_snap_id = snapshots.back().first;
        if (prev_snap_id == snap_id)
            snapshots.back().second = val;
        else
            snapshots.emplace_back(snap_id, val);
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>& snapshots = snap_ar[index];
        if (snapshots.empty()) 
            return 0;
        int left = 0, right = snapshots.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int current_snap_id = snapshots[mid].first;
            if (current_snap_id == snap_id)
                return snapshots[mid].second;
            else if (current_snap_id > snap_id)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return snapshots[right].second;
    }

private:
    int snap_id = 0;
    // pair<snap_id, value>
    vector<vector<pair<int, int>>> snap_ar;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
