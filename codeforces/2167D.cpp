// D. Yet Another Array Problem
// https://codeforces.com/contest/2167/problem/D

#include <bits/stdc++.h>

using namespace std;


long long GcdOfSet(const unordered_set<long long>& st) {
    auto it = st.begin();
    long long gcd = *it;
    ++it;
    for (; it != st.end(); ++it) {
        gcd = gcd == 1 ? 1 : std::gcd(gcd, *it);
        if (gcd == 1) {
            break;
        }
    }
    return gcd;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        long long x;
        unordered_set<long long> st;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            st.insert(x);
        }

        long long gcd_of_set = GcdOfSet(st);

        long long current = 2;
        while (gcd(gcd_of_set, current) != 1) {
            ++current;
        }
        cout << current << endl;
    }

    return 0;
}
