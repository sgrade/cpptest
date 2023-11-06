// 1845. Seat Reservation Manager
// https://leetcode.com/problems/seat-reservation-manager/

#include <bits/stdc++.h>

using namespace std;


class SeatManager {
public:
    SeatManager(int n) {
        this->n = n;
    }

    int reserve() {
        int reserved;
        if (!min_heap.empty()) {
            if (min_heap.top() < mx) {
                reserved = min_heap.top();
                min_heap.pop();
            }
        }
        else {
            reserved = mx;
            ++mx;
        }
        return reserved;
    }

    void unreserve(int seatNumber) {
        min_heap.emplace(seatNumber);
    }

private:
    int n;
    int mx = 1;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
