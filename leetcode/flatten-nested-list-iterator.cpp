// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/


#include <bits/stdc++.h>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// Based on Editorial's Approach 2: Stack
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            st.emplace(nestedList[i]);
    }
    
    int next() {
        if (!hasNext())
            throw;
        int ans = st.top().getInteger();
        st.pop();
        return ans;
    }
    
    bool hasNext() {
        makeStackTopAnInteger();
        return !st.empty();
    }

private:
    stack<NestedInteger> st;
    void makeStackTopAnInteger() {
        while (!st.empty() && !st.top().isInteger()) {
            vector<NestedInteger> nested_list = st.top().getList();
            st.pop();
            for (int i = nested_list.size() - 1; i >= 0; --i)
                st.emplace(nested_list[i]);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
