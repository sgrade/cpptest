// A. Forgotten Episode

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<bool> a(n+1);
    a[0] = true;
    
    int tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        a[tmp] = true;
    }

    int ans = distance(begin(a), find(begin(a), end(a), false));

    cout << ans << endl;

    return 0;
}
