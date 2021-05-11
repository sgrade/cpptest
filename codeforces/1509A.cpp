// A. Average Height

#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        multiset<int> odd, even;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp % 2 == 0) {
                even.insert(tmp);
            }
            else {
                odd.insert(tmp);
            }
        }

        for (auto &el: even) {
            cout << el << ' ';
        }
        for (auto &el: odd) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
