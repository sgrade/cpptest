// B. Vanya and Lanterns
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main(){

    int n, l;
    cin >> n >> l;

    set<double> st;

    double tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        st.insert(tmp);
    }

    double d = 0;
    set<double>::iterator it = st.begin();

    if (*it != 0) {
        d = *it;
    }
    ++it;

    tmp = 0;
    double dist;
    for (; it != st.end(); ++it) {
        dist = max(dist, *it - tmp);
        tmp = *it;
    }

    if (*it != l) {
        d = max(d, l - *it);
    }

    d = max (d, dist / 2);
    
    cout << d << endl;

    return 0;
}
