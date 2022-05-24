// B. Card Trick
// Time limit exceeded on test 3
 
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
 
        int n, m;
        cin >> n;
 
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
 
        cin >> m;
        vector<int> b(m);
        for (int &el: b) cin >> el;
 
        for (int i = 0; i < m; ++i) {
            rotate(a.begin(), a.begin() + b[i], a.end());
        }
 
        cout << a.front() << '\n';
    }
 
    return 0;
}