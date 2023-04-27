// 622. Design Circular Queue
// https://leetcode.com/problems/design-circular-queue/

#include <bits/stdc++.h>

using namespace std;


class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (q.size() - front_idx == k)
            return false;
        q.emplace_back(value);
        return true;
    }
    
    bool deQueue() {
        if (front_idx == q.size())
            return false;
        ++front_idx;
        return true;
    }
    
    int Front() {
        if (front_idx == q.size())
            return -1;
        return q[front_idx];
    }
    
    int Rear() {
        if (front_idx == q.size())
            return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return front_idx == q.size();
    }
    
    bool isFull() {
        return q.size() - front_idx == k;
    }

private:
    int k;
    vector<int> q;
    int front_idx = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */