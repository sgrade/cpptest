// 1381. Design a Stack With Increment Operation
// https://leetcode.com/problems/design-a-stack-with-increment-operation/

#include <bits/stdc++.h>

using namespace std;


class CustomStack {
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
    }

    void push(int x) {
        if (st.size() == max_size)
            return;
        st.emplace_back(x);
    }

    int pop() {
        if (st.empty())
            return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }

    void increment(int k, int val) {
        list<int>::iterator it = st.begin();
        if (st.size() < k)
            k = st.size();
        while (k--) {
            *it += val;
            ++it;
        }
    }

private:
    list<int> st;
    int max_size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
