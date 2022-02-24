// B. Bogosort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        sort(begin(a), end(a), greater<int>());

        for (auto &el: a) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
