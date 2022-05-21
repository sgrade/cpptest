// B1. Books Exchange (easy version)

#include <iostream>
#include <vector>

using namespace std;


int check (vector<int> &v, int idx) {
    
    int i = idx;
    int days = 0;
    
    while (true) {
        days++;
        if (v[i] == idx) {
            break;
        }
        i = v[i];
    }

    return days;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {

        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> p[i];
        }

        for (int i = 1; i < n + 1; ++i) {
            cout << check(p, i) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
