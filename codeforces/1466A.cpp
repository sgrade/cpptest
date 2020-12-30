// A. Bovine Dilemma

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &el: v) cin >> el;

        int ans = 0;

        set<int> st;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (i != j){
                    st.insert(abs(v[i] - v[j]));
                }
            }
        }

        cout << st.size() << endl;

    }

    return 0;
}
