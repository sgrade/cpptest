// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>

using namespace std;


class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (mins.empty() || val < mins.top().first) {
            mins.emplace(pair<int, int>(val, 1));
        }
        else if (val == mins.top().first) {
            ++mins.top().second;
        }
    }
    
    void pop() {
        if (mins.top().first == st.top()) {
            if (mins.top().second > 1) {
                --mins.top().second;
            }
            else {
                mins.pop();
            }
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top().first;
    }

private:
    stack<int> st;
    stack<pair<int, int>> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
