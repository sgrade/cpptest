// A. Bank Robbery

#include <iostream>

using namespace std;


int main() {

    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n; 

    int ans = 0;

    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp > b && tmp < c) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
