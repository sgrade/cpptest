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


vector<long long> AllPrimeFactors (long long n){
    vector<long long> v;
    if (n == 0 || n == 1) return v;

    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for (long long i=3; i <= sqrtl(n); i += 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }
    
    if (n > 2) v.push_back(n);

    return v;

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

        vector<long long> prime_factors = AllPrimeFactors(gcd_of_set);

        long long current = 2;
        while (true) {
            bool is_coprime = true;
            for (long long p: prime_factors) {
                if (current % p == 0) {
                    is_coprime = false;
                    break;
                }
            }
            if (is_coprime) {
                cout << current << endl;
                break;
            }
            ++current;
        }

    }

    return 0;
}
