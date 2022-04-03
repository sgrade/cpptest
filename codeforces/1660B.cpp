// B. Vlad and Candies

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

        bool ans = (n == 1 && a[0] == 1) ? true : false;

        if (n > 1) {
            if (a[n-1] - a[n-2] < 2) {
                ans = true;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
