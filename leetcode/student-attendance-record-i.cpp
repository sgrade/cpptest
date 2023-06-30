// 551. Student Attendance Record I
// https://leetcode.com/problems/student-attendance-record-i/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for (const char& ch: s) {
            if (ch == 'P')
                late = 0;
            else if (ch == 'L') {
                ++late;
                if (late == 3)
                    return false;
            }
            else if (ch == 'A') {
                ++absent;
                if (absent == 2)
                    return false;
                late = 0;
            }
        }
        return true;
    }
};
