// A. Olympiad

#include <iostream>
#include <set>

using namespace std;


int main(){

    int n;
    cin >> n;

    set<int> st;
    int tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        st.insert(tmp);
    }

    int ans = st.size();
    if (st.find(0) != st.end()) --ans;

    cout << ans << endl;

    return 0;
}
