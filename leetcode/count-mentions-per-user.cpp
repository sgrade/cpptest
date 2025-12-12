// 3433. Count Mentions Per User
// https://leetcode.com/problems/count-mentions-per-user/

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Based on Editorial's Approach: Playback After Sorting
class Solution {
 public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    sort(events.begin(), events.end(),
         [](const vector<string>& e1, const vector<string>& e2) {
           int time1 = stoi(e1[1]);
           int time2 = stoi(e2[1]);

           if (time1 != time2) {
             return time1 < time2;
           }
           return e1[0] != "MESSAGE" && e2[0] == "MESSAGE";
         });

    vector<int> counter(numberOfUsers), next_online(numberOfUsers);
    for (const vector<string>& event : events) {
      int cur_time = stoi(event[1]);
      if (event[0] == "MESSAGE") {
        if (event[2] == "ALL") {
          for (int user_id = 0; user_id < numberOfUsers; user_id++) {
            counter[user_id]++;
          }
        } else if (event[2] == "HERE") {
          for (int user_id = 0; user_id < numberOfUsers; user_id++) {
            if (next_online[user_id] <= cur_time) {
              counter[user_id]++;
            }
          }
        } else {
          // Handle user ID list (space-separated: "id0 id3 id5")
          std::istringstream iss(event[2]);
          string str_id;
          while (iss >> str_id) {
            int user_id = stoi(str_id.substr(2));  // Skip "id" prefix
            counter[user_id]++;
          }
        }
      } else {
        int user_id = stoi(event[2]);
        next_online[user_id] = cur_time + 60;
      }
    }

    return counter;
  }
};
