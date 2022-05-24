// B. Card Trick
 
#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        int n, m;

        cin >> n;
        vector<int> a(n);        
        for (int &el: a) cin >> el;
 
        cin >> m;
        vector<int> b(m);
        for (int &el: b) cin >> el;
 
        // Idea from - https://codeforces.com/contest/1681/submission/158153598
        long long sum = accumulate(b.begin(), b.end(), 0LL);
        int rem = sum % n;
        
        cout << a[sum % n] << '\n';
    }
 
    return 0;
}