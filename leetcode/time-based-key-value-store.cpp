// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>

using namespace std;


class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        time_map[key].emplace_back(pair<int, string>(timestamp, value));
        timestamps[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (time_map.find(key) == time_map.end())
            return "";
        if (timestamps.find(timestamp) != timestamps.end())
            return timestamps[timestamp];
        vector<pair<int, string>>& values = time_map[key];
        string value = binary_search(time_map[key], timestamp);
        return value;
    }

    string binary_search (vector<pair<int, string>>& v, int& timestamp) {
        if (timestamp < v[0].first)
            return "";
        int left = 0, right = v.size(), mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (v[mid].first < timestamp)
                left = mid + 1;
            else 
                right = mid;
        }
        return v[right - 1].second;
    }

private:
    // key -> vector<pair<timestamp, value>>
    unordered_map<string, vector<pair<int, string>>> time_map;
    // timestamp -> value
    unordered_map<int, string> timestamps;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
