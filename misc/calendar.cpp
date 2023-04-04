// Yandex / Nebius

// Assumptions:
// We are solving not an artificial, but a real life problem with constraints people usually see in practice
// Specifically, the search interval is relatively short (e.g. endTime - startTime <= 10 * duration)
// The merge of busy_intervals is done only for this short interval. Thus, the time/space complexity 
// for per-row traversal with merge (O(num_of_people * num_of_meetings_per_person_in_search_interval)) has 
// minimal impact on the end result. The data structure for TCalendar influences the result much more. Thus,
// if the algo is to be generalized to a wider dataset or frequent lookups, I would convert the TCalendar 
// from vector to a data structure optimized for target lookups. In this case, we would not search from the beginning 
// of the calendars each time we call FindSlot.
// If the search inteval (endTime - startTime) is infinity, I would break it into a set of relatively short chunks and
// make recursive calls for the chunks (each FindSlot call still targets a relatively short interval, e.g. a day). 
// Then we would need to store the last chunk traversal results in a helper data structure. With that, the 
// the subsequent calls of FindSlot would start not from the beginning of each calendar, but from the meeting we stopped last time.


#include <bits/stdc++.h>

using namespace std;


struct TMeeting {
    int StartTime = 0;
    int EndTime = 0;
};

using TCalendar = vector<TMeeting>;

struct TResult {
    bool Status = false;
    int StartTime = 0;
};

// Each invited[i] is sorted by StartTime's (no need to check)
// Each TMeeting.StartTime < TMeeting.EndTime (no need to check)
TResult FindSlot(const vector<TCalendar>& invited, int startTime, int endTime, int duration) {

    TResult ans;

    int persons = invited.size();
    vector<pair<int, int>> busy_intervals;
    for (int person = 0; person < persons; ++person) {
        int meeting;
        int meetings = invited[person].size();
        // Skip the meetings, which end before the target interval
        for (meeting = 0; meeting < meetings; ++meeting) {
            if (invited[person][meeting].EndTime <= startTime)
                continue;
            else
                break;
        }
        // Only store the meetings in the target interval
        for (; meeting < meetings; ++meeting) {
            int current_start = invited[person][meeting].StartTime;
            // Break the search when found a meeting starting after the target interval
            if (current_start > endTime)
                break;
            int current_end = invited[person][meeting].EndTime;
            busy_intervals.emplace_back(pair<int, int>(current_start, current_end));
        }
    }

    if (busy_intervals.empty()) {
        ans.Status = true;
        ans.StartTime = startTime;
        return ans;
    }

    sort (busy_intervals.begin(), busy_intervals.end());

    vector<pair<int, int>> merged;
    int start = busy_intervals[0].first, end = busy_intervals[0].second;
    for (int i = 1; i < busy_intervals.size(); ++i) {
        int current_start = busy_intervals[i].first;
        if (end < current_start) {
            merged.emplace_back(pair<int, int>(start, end));
            start = current_start;
        }
        int current_end = busy_intervals[i].second;
        end = max (end, current_end);
    }
    merged.emplace_back(pair<int, int>(start, end));

    start = merged[0].first;
    if (startTime + duration <= start) {
        ans.Status = true;
        ans.StartTime = start;
        return ans;
    }
    end = merged[0].second;
    for (int i = 1; i < merged.size(); ++i) {
        start = merged[i].first;
        if (end + duration <= start) {
            ans.Status = true;
            ans.StartTime = end;
            return ans;
        }
        end = merged[i].second;
    }
    if (end + duration <= endTime) {
        ans.Status = true;
        ans.StartTime = end;
        return ans;
    }

    return ans;
};


int main() {

    // TESTCASE 1
    // search: (3, 4)
    // [(1, 2)]
    // [(10, 1000)]

    vector<TCalendar> invited;
    
    TCalendar cal1, cal2;
    
    TMeeting cal1_m1;
    cal1_m1.StartTime = 1;
    cal1_m1.EndTime = 2;
    cal1.emplace_back(cal1_m1);

    TMeeting cal2_m1;
    cal2_m1.StartTime = 10;
    cal2_m1.EndTime = 1000;
    cal2.emplace_back(cal2_m1);

    invited.emplace_back(cal1);
    invited.emplace_back(cal2);

    TResult tc1 = FindSlot(invited, 3, 4, 1);
    cout << "Testcase1" << endl;
    cout << "Status: " << (tc1.Status == true ? "true" : "false") << endl;
    cout << "StartTime: " << tc1.StartTime << endl;


    // TESTCASE 2
    // search: (1020, 1040, 4)
    // [(1, 2), (5, 1020), (1030, 2000)]
    // [(10, 1000), (1020, 1025)]
    
    TMeeting cal1_m2;
    cal1_m2.StartTime = 5;
    cal1_m2.EndTime = 1020;
    invited[0].emplace_back(cal1_m2);
    TMeeting cal1_m3;
    cal1_m3.StartTime = 1030;
    cal1_m3.EndTime = 2000;
    invited[0].emplace_back(cal1_m3);

    TMeeting cal2_m2;
    cal2_m2.StartTime = 1020;
    cal2_m2.EndTime = 1025;
    invited[1].emplace_back(cal2_m2);

    TResult tc2 = FindSlot(invited, 1020, 1040, 4);
    cout << "Testcase2" << endl;
    cout << "Status: " << (tc2.Status == true ? "true" : "false") << endl;
    cout << "StartTime: " << tc2.StartTime << endl;


    // TESTCASE 3
    // search: (1020, 1040, 4)
    // [(1, 2), (5, 1020), (1030, 2000)]
    // [(10, 1000), (1020, 1025), (1027, 1030)]

    TMeeting cal2_m3;
    cal2_m3.StartTime = 1027;
    cal2_m3.EndTime = 1030;
    invited[1].emplace_back(cal2_m3);

    TResult tc3 = FindSlot(invited, 1020, 1040, 4);
    cout << "Testcase3" << endl;
    cout << "Status: " << (tc3.Status == true ? "true" : "false") << endl;
    cout << "StartTime: " << tc3.StartTime << endl;


    return 0;
}
