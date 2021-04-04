// A. Chores

#include <iostream>

using namespace std;


int main() {

    int n, k, x;
    cin >> n >> k >> x;

    int a[n];
    for (auto &el: a)
        cin >> el;
    
    int ans = 0;
    for (int i = 0; i < n-k; ++i) {
        ans += a[i];
    }
    ans += k * x;

    cout << ans << endl;

    return 0;
}
