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
       

    // Traverse by colums - NOT FINISHED
    // ------X-
    // -------X
    // -X-X----
    
    int rows = invited.size();
    int cols = invited[0].size();   // min of each calendar
    
    // vector<int> cols = new vector<int>(invited.size());
    // for (int col = 0; col < cols; ++col) {
    //     for (int row = 0; row < rows; ++row) {
    //         //
            
    //     }
    // }
};
