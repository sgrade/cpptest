// 3508. Implement Router
// https://leetcode.com/problems/implement-router/

#include <bits/stdc++.h>

using namespace std;


// Custom hash function object std::pair
struct PairHash {
    std::size_t operator()(const pair<int, int>& p) const noexcept {
        auto hash1 = std::hash<int>{}(p.first);
        auto hash2 = std::hash<int>{}(p.second);
        // A common technique Inspired by boost::hash_combine
        return hash1 ^ (hash2 << 1);
    }
};

class Router {
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit; 
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (timestamp != current_time) {
            current_time = timestamp;
            packets_for_current_timestamp.clear();
        }
        if (q.size() == memoryLimit) {
            auto _ = forwardPacket();
        }
        if (packets_for_current_timestamp.count({source, destination})) {
            return false;
        }
        packets_for_current_timestamp.emplace(source, destination);
        dst_to_timestamp[destination].emplace(timestamp);
        q.emplace(vector<int>{source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }
        vector<int>& front = q.front();
        int src = front[0], dst = front[1], timestamp = front[2];
        packets_for_current_timestamp.erase({src, dst});
        vector<int> packet{src, dst, timestamp};
        auto it = dst_to_timestamp[dst].find(timestamp);
        if (it != dst_to_timestamp[dst].end()) dst_to_timestamp[dst].erase(it);
        q.pop();
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (dst_to_timestamp.find(destination) == dst_to_timestamp.end()) {
            return 0;
        }
        multiset<int>& st = dst_to_timestamp[destination];
        auto left = st.lower_bound(startTime);
        auto right = st.upper_bound(endTime);
        int cnt = distance(left, right);
        return cnt;
    }

private:
    size_t memoryLimit;
    queue<vector<int>> q;
    int current_time;
    unordered_set<pair<int, int>, PairHash> packets_for_current_timestamp;
    map<int, multiset<int>> dst_to_timestamp;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
