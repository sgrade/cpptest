// A. Copying Homework

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &el: a) cin >> el;

    for (int i = 0; i < n; ++i) {
        cout << n - a[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
