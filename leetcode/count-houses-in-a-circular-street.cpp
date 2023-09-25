// 2728. Count Houses in a Circular Street
// https://leetcode.com/problems/count-houses-in-a-circular-street/

#include <bits/stdc++.h>

using namespace std;


// Definition for a street.
class Street {
public:
    Street(vector<int> doors);
    void openDoor();
    void closeDoor();
    bool isDoorOpen();
    void moveRight();
    void moveLeft();
};

class Solution {
public:
    int houseCount(Street* street, int k) {
        int ans = 0;
        while (k--) {
            street->openDoor();
            street->moveRight();
        }
        while (street->isDoorOpen()) {
            ++ans;
            street->closeDoor();
            street->moveRight();
        }
        return ans;
    }
};
