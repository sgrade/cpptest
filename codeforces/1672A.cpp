// A. Log Chopping

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

        int tmp;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            cnt += tmp - 1;
        }

        if (cnt % 2 != 0) {
            cout << "errorgorn\n";
        }
        else {
            cout << "maomao90\n";
        }
    }

    return 0;
}
