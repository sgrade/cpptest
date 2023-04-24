// 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2: Sorted List + Binary Search
class MyCalendar {
public:
    bool book(int start, int end) {
        const pair<int, int> event(start, end);
        const set<pair<int, int>>::iterator next_event = calendar.lower_bound(event);
        if (next_event != calendar.end() && next_event->first < end)
            return false;
        if (next_event != calendar.begin()) {
            const set<pair<int, int>>::iterator prev_event = prev(next_event);
            if (prev_event->second > start)
                return false;
        }
        calendar.emplace(event);
        return true;
    }
private:
    set<pair<int, int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
