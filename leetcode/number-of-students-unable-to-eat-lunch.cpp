// 1700. Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Counting
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero_students = count(students.begin(), students.end(), 0);
        int one_students = students.size() - zero_students;
        for (const int& sandwich: sandwiches) {
            if (sandwich == 0 && zero_students == 0)
                return one_students;
            if (sandwich == 1 && one_students == 0)
                return zero_students;
            if (sandwich == 0)
                --zero_students;
            else
                --one_students;
        }
        return 0;
    }
};
