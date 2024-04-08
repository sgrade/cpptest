// 1700. Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero_students = count(students.begin(), students.end(), 0);
        int zero_sandwiches = count(sandwiches.begin(), sandwiches.end(), 0);
        if (zero_sandwiches - zero_students == 0)
            return 0;

        // which type of sandwiches exceed number of students which want it?
        // Note: nobody will want this type of sandwich after all students,
        // who want it, get it, so the queue stops
        int sandwich_type = 1;
        if (zero_sandwiches > zero_students)
            sandwich_type = 0;

        int student_count = sandwich_type == 0 ? zero_students : students.size() - zero_students;
        queue<int> q;
        for (const int& student: students)
            q.emplace(student);
        int i = 0;
        while (i < sandwiches.size()) {
            int current_student = q.front();
            q.pop();
            if (current_student == sandwiches[i]) {
                ++i;
                if (current_student == sandwich_type)
                    --student_count;
            }
            else
                q.emplace(current_student);

            if (sandwich_type == sandwiches[i] && student_count == 0)
                break;
        }
        return q.size();
    }
};
