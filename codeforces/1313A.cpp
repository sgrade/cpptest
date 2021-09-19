// A. Fast Food Restaurant

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;
    
    while (t--) {

        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(begin(v), end(v), greater<int>());
        
        int a = v[0], b = v[1], c = v[2];
        
        int ans = 0;

        if (a > 0) {
            ++ans;
            --a;
        }
        if (b > 0) {
            ++ans;
            --b;
        }
        if (c > 0) {
            ++ans;
            --c;
        }

        if (a > 0 && b > 0) {
            ++ans;
            --a;
            --b;
        }
        if (b > 0 && c > 0) {
            ++ans;
            --b;
            --c;
        }
        if (c > 0 && a > 0) {
            ++ans;
            --c;
            --a;
        }

        if (a > 0 && b > 0 && c > 0) {
            ++ans;
        }

        cout << ans << endl;

    }

    return 0;
}
