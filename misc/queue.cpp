#include <cstdint>
#include <iostream>
#include <queue>
#include <assert.h>
#include <limits>
#include <map>
#include <deque>


#define NDEBUG

using namespace std;


class Solution {
public:

  Solution() {
    current_max_ = numeric_limits<int>::min();
  };

  void pushElement(int x) {
    q_.push(x);
    current_max_ = max(current_max_, x);
    ++counter_[x];
  }

  int getFront() {
    assert(!q_.empty());
    int tmp = q_.front();
    q_.pop();
    if (counter_[tmp] > 1) {
      --counter_[tmp];
    }
    else {
      counter_.erase(tmp);
    }
    current_max_ = counter_.rbegin()->first;
    return tmp;
  }

  int getMax() {
    assert(!q_.empty());
    return current_max_;
  }

private:
  queue<int> q_;
  int current_max_;
  map<int, int> counter_;
};


int main() {

  Solution sol;
  sol.pushElement(-7); // 
  sol.pushElement(-8); // 
  cout << sol.getMax() << endl; // 
  sol.pushElement(-9); // 
  cout << sol.getMax() << endl; // 
  sol.getFront(); // 7
  cout << sol.getMax() << endl;
  cout << "End of tests" << endl;
        
  return 0;
}

class Solution2 {
public:

  Solution2() {
  };

  void pushElement(int x) {
    q_.push(x);
    while (!maxes_.empty() && maxes_.back() < x) {
        maxes_.pop_back();
    } 
  }

  int getFront() {
    assert(!q_.empty());
    int tmp = q_.front();
    q_.pop();
    if (maxes_.front() == tmp) {
        maxes_.pop_front();
    }
    return tmp;
  }

  int getMax() {
    assert(!q_.empty());
    return maxes_.front();
  }

private:
  queue<int> q_;
  deque<int> maxes_;
};

// 9 7 4 2 1 5 
// 9 7 5
