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


// Optimized with an idea from Sample 0 ms submission
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        parse(nestedList);
    }
    
    int next() {
        int next_integer = q.front();
        q.pop();
        return next_integer;
    }
    
    bool hasNext() {
        return !q.empty();
    }

private:
    queue<int> q;
    void parse(const vector<NestedInteger>& nested_list) {
        for (const NestedInteger& ni: nested_list) {
            if (ni.isInteger())
                q.emplace(ni.getInteger());
            else
                parse(ni.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
