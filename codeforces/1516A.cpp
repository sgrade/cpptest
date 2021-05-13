// A. Tit for Tat

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        int i = 0;
        
        while (k--) {
            while (a[i] == 0 && i < n-2) {
                ++i;
            }

            if (a[i] > 0) {
                --a[i];
                ++a[n-1];
            }
        }

        for (auto &el: a) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
