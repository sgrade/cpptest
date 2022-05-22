// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) 
    : size_(size)
    {
        
    }
    
    double next(int val) {
        a.push_back(val);
        cnt_ = min(int(a.size()), size_);
        sm = accumulate(a.end() - cnt_, a.end(), 0.0);
        ans = sm / cnt_;
        return ans;
    }
private:
    int size_;
    vector<int> a;
    double cnt_ = 1.0;
    double ans = 0;
    double sm = 0;
};
