// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2 (Two Stacks) Push - O(1)O(1)O(1) per operation, Pop - Amortized O(1)O(1)O(1) per operation.
// Optimized with sample 0 ms solution
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (st1.empty())
            frnt = x;
        st1.emplace(x);
    }
    
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()){
                st2.emplace(st1.top());
                st1.pop();
            }
        }
        int prev_front = st2.top();
        st2.pop();
        return prev_front;
    }
    
    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.emplace(st1.top());
                st1.pop();
            }
        }
        return st2.top();
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
