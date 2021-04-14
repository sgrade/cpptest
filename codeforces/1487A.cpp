// A. Arena

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int a[n];
        for (auto &el: a) {
            cin >> el;
        }
        sort(a, a+n);

        int cnt = count(a, a+n, a[0]);
        cout << n - cnt << endl;

    }

    return 0;
}
