// 281. Zigzag Iterator
// https://leetcode.com/problems/zigzag-iterator/

#include <bits/stdc++.h>

using namespace std;


class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size(), n = n1 + n2;
        int idx1 = 0, idx2 = 0;
        bool even = true;
        while (n--) {
            if (idx1 < n1 && even) {
                q.emplace(v1[idx1++]);
                if (idx2 < n2) {
                    even = false;
                }
            }
            else {
                q.emplace(v2[idx2++]);
                if (idx1 < n1) {
                    even = true;
                }
            }
        }
    }

    int next() {
        int frnt = q.front();
        q.pop();
        return frnt;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
