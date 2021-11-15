// 

#include <iostream>

using namespace std;
using ll = long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll u, v;
        cin >> u >> v;

        // Idea - https://codeforces.com/contest/1589/submission/135342982

        ll x = u * u, y = - v * v;

        cout << x << ' ' << y << endl;

    }

    return 0;
}
