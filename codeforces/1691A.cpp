// A. Beat The Odds

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int odd = 0, even = 0;
        for (int &el: a) {
            if (el % 2 == 0) ++even;
            else ++odd;
        }

        cout << min(odd, even) << '\n';

    }

    return 0;
}
