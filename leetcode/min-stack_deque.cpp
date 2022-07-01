// 155. Min Stack
// https://leetcode.com/problems/min-stack/

/*
Runtime: 76 ms, faster than 9.14% of C++ online submissions for Min Stack.
Memory Usage: 24.3 MB, less than 5.60% of C++ online submissions for Min Stack.
*/

#include <bits/stdc++.h>

using namespace std;


class MinStack {
public:
    stack<int> st;
    int mn = numeric_limits<int>::max();
    deque<int> mins;
    
    MinStack() {
    }
    
    void push(int val) {
        mn = min(mn, val);
        st.push(val);
        vector<int> tmp;
        while (!mins.empty() && mins.back() > val) {
            tmp.emplace_back(mins.back());
            mins.pop_back();
        }
        mins.push_back(val);
        if (!tmp.empty()) {
            reverse(tmp.begin(), tmp.end());
            move(tmp.begin(), tmp.end(), back_inserter(mins));
        }
    }
    
    void pop() {
        int x = st.top();
        st.pop();
        vector<int> tmp;
        while (mins.back() != x) {
            tmp.emplace_back(mins.back());
            mins.pop_back();
        }
        mins.pop_back();
        if (!tmp.empty()) {
            reverse(tmp.begin(), tmp.end());
            move(tmp.begin(), tmp.end(), back_inserter(mins));
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
