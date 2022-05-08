// B1. Tokitsukaze and Good 01-String (easy version)
 
#include <iostream>
#include <string>
 
using namespace std;
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        int n;
        cin >> n;
 
        string s;
        cin >> s;
 
        int ops = 0;
 
        for (int i = 1; i < n; i += 2) {
            
            if (s[i] == s[i-1]) {
                continue;
            }
 
            else {
                ++ops;
            }
        }
 
        cout << ops << '\n';
    }
 
    return 0;
}
