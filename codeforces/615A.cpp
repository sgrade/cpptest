// A. Bulbs

#include <iostream>
#include <set>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    set<int> st;
    int tmp;
    for (int i=0; i<n; ++i){
        int b;
        cin >> b;
        for (int j=0; j<b; ++j){
            cin >> tmp;
            st.insert(tmp);
        }
    }

    bool ans = false;
    if (st.size() == m) ans = true;

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}
