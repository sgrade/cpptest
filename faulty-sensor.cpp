// 1826. Faulty Sensor
// https://leetcode.com/problems/faulty-sensor/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size();
        int i = 0;
        while (i < n && sensor1[i] == sensor2[i])
            ++i;
        
        if (i >= n - 1)
            return -1;
        
        // Optimized with an idea from a sample solution
        bool can_be_one = true, can_be_two = true;
        for (; i < n - 1; ++i) {
            if (can_be_one && sensor1[i] != sensor2[i + 1])
                can_be_one = false;
            if (can_be_two && sensor2[i] != sensor1[i + 1])
                can_be_two = false;
        }

        if (can_be_one && can_be_two)
            return -1;
        else if (can_be_one)
            return 1;
        else if (can_be_two)
            return 2;
        else
            return -1;
    }
};
