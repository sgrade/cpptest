// B. Non-Substring Subsequence

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, q;
        cin >> n >> q;

        string s;
        getline(cin >> ws, s);

        while(q--){
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            bool ans = false;

            string sub = s.substr(l, r - l + 1);
            size_t foundL = string::npos;
            size_t foundR = string::npos;
            if (l > 0) {
                string subL = s.substr(0, l);
                foundL = subL.find(sub[0]);
            }
            if (r < n - 1) {
                string subR = s.substr(r + 1);
                foundR = subR.find(sub[sub.size()-1]);
            }
            if (foundL != string::npos || foundR != string::npos){
                ans = true;
            }

            cout << (ans ? "YES\n" : "NO\n");
        }

    }

    return 0;
}
