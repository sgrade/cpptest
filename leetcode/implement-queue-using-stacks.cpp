// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>

using namespace std;


class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.emplace(x);
        if (st1.size() == 1) {
            frnt = x;
        }
    }
    
    int pop() {
        while(st1.size() > 1) {
            st2.emplace(st1.top());
            st1.pop();
        }
        int former_front = st1.top();
        st1.pop();

        if (!st2.empty()) {
            frnt = st2.top();
        }
        while(!st2.empty()) {
            st1.emplace(st2.top());
            st2.pop();
        }
        return former_front;
    }
    
    int peek() {
        return frnt;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }

private:
    stack<int> st1, st2;
    int frnt;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
