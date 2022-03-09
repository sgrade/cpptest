// B. Quality vs Quantity

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


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
        sort(begin(a), end(a), greater<int>());

        bool ans = false;

        ll sum_red = 0LL + a[0], sum_blue = 0LL + a[n-1] + a[n-2];
        int idx_red = 0, idx_blue = n-2;
        
        while (idx_red < idx_blue) {
            if (sum_red > sum_blue) {
                ans = true;
                break;
            }
            ++idx_red;
            --idx_blue;
            sum_red += a[idx_red];
            sum_blue += a[idx_blue];
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
