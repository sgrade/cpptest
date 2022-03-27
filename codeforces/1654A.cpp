// A. Maximum Cake Tastiness

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
        for (int &el: a) {
            cin >> el;
        }

        sort(begin(a), end(a));

        cout << a[n-1] + a[n-2] << '\n';
    }

    return 0;
}
