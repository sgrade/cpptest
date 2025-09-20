// 3508. Implement Router
// https://leetcode.com/problems/implement-router/

#include <bits/stdc++.h>
// use only the specific std symbols we need (avoid using namespace std)
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::deque;
using std::pair;
using std::size_t;
using std::lower_bound;
using std::upper_bound;
using std::distance;
using std::hash;


// Custom hash function object std::pair
struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);
        // A common technique Inspired by boost::hash_combine
        return hash1 ^ (hash2 << 1);
    }
};

class Router {
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
        current_time = INT_MIN;
        nextPacketId = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (timestamp != current_time) {
            current_time = timestamp;
            packets_for_current_timestamp.clear();
        }
        if (packets_for_current_timestamp.count({source, destination})) {
            return false;
        }
        if (q.size() == memoryLimit) {
            auto _ = forwardPacket();
        }
        packets_for_current_timestamp.emplace(source, destination);
        // insert timestamp into sorted vector for destination
        auto &vec = dst_to_timestamp[destination];
        auto pos = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(pos, timestamp);
        q.emplace_back(Packet{source, destination, timestamp, 0});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet front = q.front();
        q.pop_front();
        int src = front.src, dst = front.dst, timestamp = front.timestamp, id = front.id;
        vector<int> packet{src, dst, timestamp};
        auto mapIt = dst_to_timestamp.find(dst);
        if (mapIt != dst_to_timestamp.end()) {
            auto &vec = mapIt->second;
            auto it = lower_bound(vec.begin(), vec.end(), timestamp);
            if (it != vec.end() && *it == timestamp) vec.erase(it);
            if (vec.empty()) dst_to_timestamp.erase(mapIt);
        }
        if (timestamp == current_time) {
            packets_for_current_timestamp.erase({src, dst});
        }
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = dst_to_timestamp.find(destination);
        if (it == dst_to_timestamp.end()) return 0;
        auto &vec = it->second;
        // vec is maintained sorted; use lower_bound/upper_bound
        auto l = lower_bound(vec.begin(), vec.end(), startTime);
        auto r = upper_bound(vec.begin(), vec.end(), endTime);
        return int(distance(l, r));
    }

private:
    size_t memoryLimit;
    struct Packet { int src, dst, timestamp, id; };
    deque<Packet> q;
    int current_time;
    int nextPacketId;
    unordered_set<pair<int, int>, PairHash> packets_for_current_timestamp;
    // For LeetCode compatibility: per-destination sorted vector of timestamps
    unordered_map<int, vector<int>> dst_to_timestamp;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
