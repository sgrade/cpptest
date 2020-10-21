// A. Remove Duplicates

#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it: v) {
        cin >> it;
        
    }

    set<int> st;
    stack<int> ans;
    for (auto it=v.rbegin(); it != v.rend(); ++it){
        if (st.find(*it) == st.end()){
            st.insert(*it);
            ans.push(*it);
        }
    }

    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << endl;

    return 0;
}