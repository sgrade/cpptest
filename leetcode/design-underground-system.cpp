// 1396. Design Underground System
// https://leetcode.com/problems/design-underground-system/

#include <bits/stdc++.h>

using namespace std;


class UndergroundSystem {
public:
    UndergroundSystem() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = pair<string, int>(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& [checkin_station, checkin_time] = checkins[id];
        double travel_time = t - checkin_time;
        string stations = checkin_station + "-" + stationName;
        if (average_time.find(stations) == average_time.end()) {
            average_time[stations] = pair<double, int>(travel_time, 1);
        }
        else {
            average_time[stations].first += travel_time;
            ++average_time[stations].second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string stations = startStation + "-" + endStation;
        return average_time[stations].first / average_time[stations].second;
    }

private:
    unordered_map<int, pair<string, int>> checkins;
    unordered_map<string, pair<double, int>> average_time;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
