// B. Last minute enhancements

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

        //int ans = 1;

        set<int> st;
        st.insert(v[0]);
        if (n > 1){
            for (int i = 1; i < n; ++i){
                if (v[i] == *st.rbegin()) {
                    st.insert(++v[i]);
                }
                else st.insert(v[i]);
            }
        }

        cout << st.size() << endl;

    }

    return 0;
}
