// 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Line Sweep
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        max_overlaps_allowed = 2;
    }

    bool book(int start, int end) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ++booking_count[start];
        --booking_count[end];
        int overlaps = 0;
        for (const auto[_, cnt]: booking_count) {
            overlaps += cnt;
            if (overlaps > max_overlaps_allowed) {
                --booking_count[start];
                ++booking_count[end];
                if (booking_count[start] == 0)
                    booking_count.erase(start);
                if (booking_count[end] == 0)
                    booking_count.erase(end);
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> booking_count;
    int max_overlaps_allowed;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
