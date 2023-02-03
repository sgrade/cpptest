// 281. Zigzag Iterator
// https://leetcode.com/problems/zigzag-iterator/

#include <bits/stdc++.h>

using namespace std;


// Based on one of the Leetcode's accepted solutions
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        its.emplace_back(v1.begin());
        its.emplace_back(v2.begin());
        ends.emplace_back(v1.end());
        ends.emplace_back(v2.end());
        done.emplace_back(v1.empty());
        done.emplace_back(v2.empty());
        turn = done[0] ? 1 : 0;
    }

    int next() {
        ans = *(its[turn]++);
        if (its[turn] == ends[turn]) done[turn] = true;
        if (!done[1 - turn]) turn = 1 - turn;
        return ans;
    }

    bool hasNext() {
        return !done[turn];
    }

private:
    int turn;
    vector<bool> done;
    vector<vector<int>::iterator> its;
    vector<vector<int>::iterator> ends;
    int ans;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
