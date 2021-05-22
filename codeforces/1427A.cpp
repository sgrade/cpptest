// A. Avoiding Zero

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        int sm = 0;
        for (auto &el: a) {
            cin >> el;
            sm += el;
        }

        // Editorial - 

        bool ans = sm == 0 ? false : true;
        
        if (sm > 0) {
            sort(begin(a), end(a), greater<int>());
        }
        else if (sm < 0) {
            sort(begin(a), end(a));

        }

        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            for (auto &el: a) {
                cout << el << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
