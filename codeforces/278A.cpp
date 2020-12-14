// A. Circle Line

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    int d[n];
    for (auto &el: d) cin >> el;

    int s, t;
    cin >> s >> t;
    --s;
    --t;

    if (s > t) swap(s, t);

    int s1 = accumulate(d+s, d+t, 0);
    int s2 = accumulate(d+t, d+n, 0) + accumulate(d, d+s, 0);

    cout << min(s1, s2) << endl;

    return 0;
}
