// A. Game with Cards

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;
        sort(a.begin(), a.end());

        cin >> m;
        vector<int> b(m);
        for (int &el: b) cin >> el;
        sort(b.begin(), b.end());

        cout << (a[n-1] >= b[m-1] ? "Alice\n" : "Bob\n");
        cout << (b[m-1] >= a[n-1] ? "Bob\n" : "Alice\n");
    }

    return 0;
}
