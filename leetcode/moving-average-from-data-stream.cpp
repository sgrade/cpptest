// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) {
        size_ = size;
        sm = 0.0;
        ans = 0.0;
    }
    
    double next(int val) {
        if (q.size() == size_) {
            sm -= q.front();
            q.pop();
        }
        sm += val;
        q.emplace(val);
        return sm / q.size();
    }
    
private:
    int size_;
    queue<int> q;
    double sm, ans;
};
