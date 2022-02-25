// B. Assigning to Classes

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
        
        vector<int> a(2*n);
        for (auto &el: a) {
            cin >> el;
        }
        sort(begin(a), end(a));
        
        int ans = a[n] - a[n-1];

        cout << ans << '\n';
    }

    return 0;
}
