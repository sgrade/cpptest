// 2446. Determine if Two Events Have Conflict
// https://leetcode.com/problems/determine-if-two-events-have-conflict/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        pair<int, int> e1(Convert(event1[0]), Convert(event1[1]));
        pair<int, int> e2(Convert(event2[0]), Convert(event2[1]));
        if (e1 > e2)
            swap(e1, e2);
        return e1.second >= e2.first;
    }
private:
    int Convert(const string& time) {
        int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3, 2));
        return h * 60 + m;
    }
};
