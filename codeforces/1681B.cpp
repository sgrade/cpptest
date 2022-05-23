// B. Card Trick
// Time limit exceeded on test 3
 
#include <iostream>
#include <algorithm>
#include <list>
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
 
        list<int> a;
        
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a.push_back(tmp);
        }
 
        cin >> m;
        vector<int> b(m);
        for (int &el: b) cin >> el;
 
        list<int>::iterator it;
        for (int i = 0; i < m; ++i) {
            it = next(a.begin(), b[i]);           
            a.splice(a.end(), a, a.begin(), it);
        }
 
        cout << a.front() << '\n';
    }
 
    return 0;
}