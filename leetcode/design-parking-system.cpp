// 1603. Design Parking System
// https://leetcode.com/problems/design-parking-system/

#include <bits/stdc++.h>

using namespace std;


class ParkingSystem {
public:
    map<int, int> num_of_slots;
    ParkingSystem(int big, int medium, int small) {
        num_of_slots[1] = big;
        num_of_slots[2] = medium;
        num_of_slots[3] = small;
    }
    bool addCar(int carType) {
        if (num_of_slots[carType] > 0) {
            --num_of_slots[carType];
            return true;
        }
        return  false;
    }
};
