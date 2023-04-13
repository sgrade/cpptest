// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>

using namespace std;

// TLE
class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        time_map[key].emplace_back(pair<int, string>(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        // Idea for the binary search implementation is from Sample 264 ms submission
        auto v_it = time_map.find(key);
        if (v_it == time_map.end())
            return "";
        vector<pair<int, string>> values = v_it->second;
        if (timestamp < values[0].first)
            return "";
        auto it = upper_bound (values.begin(), values.end(), timestamp, 
        [](const int value, const pair<int, string>& p){
            return value < p.first;
        });
        if (it == values.end()) {
            return values.rbegin()->second;
        }
        --it;
        return it->second;
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
