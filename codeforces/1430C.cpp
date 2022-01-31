// C. Numbers on Whiteboard

#include <iostream>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        cout << 2 << '\n';

        cout << n << ' ' << n-1 << '\n';
        for (int i = n; i > 2; --i) {
            cout << i << ' ' << i - 2 << '\n';
        }

    }

    return 0;
}
