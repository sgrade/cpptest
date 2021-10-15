// E1. Permutation Minimization by Deque

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<int> p;
        int tmp;
        cin >> tmp;
        p.push_front(tmp);
        for (int i = 1; i < n; ++i) {
            cin >> tmp;
            if (tmp <= p[0]) {
                p.push_front(tmp);
            }
            else {
                p.push_back(tmp);
            }
        }

        for (auto &el: p) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
