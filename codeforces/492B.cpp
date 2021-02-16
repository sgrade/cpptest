// B. Vanya and Lanterns

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;


int main(){

    int n, l;
    cin >> n >> l;

    set<long double> st;

    long double tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        st.insert(tmp);
    }

    long double d = 0;
    
    // If the first lantern is not in point 0
    if (*st.begin() != 0) 
    {
        d = *st.begin();
    }
    // If the last lantern is not in point l
    if (*st.rbegin() != l)
    {
        d = max(d, l - *st.rbegin());
    }

    set<long double>::iterator it = st.begin();
    long double dist = 0, previous = *it;
    ++it;
    for (; it != st.end(); ++it) {
        dist = max(dist, *it - previous);
        previous = *it;
    }

    d = max(d, dist / 2);

    cout << setprecision(10) << fixed;
    cout << d << endl;

    return 0;
}
