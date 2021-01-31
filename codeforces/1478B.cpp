// B. Nezzar and Lucky Number

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int q, d;
        cin >> q >> d;

        vector<int> v(q);
        for (auto &el: v) cin >> el;

        string d_str = to_string(d);

        // Key ideas - https://codeforces.com/contest/1478/submission/105769747
        for (auto num: v) {

            if (num >= 10 * d) {
                cout << "YES" << endl;
                continue;
            }

            while (to_string(num).find(d_str) == string::npos){
                num -= d;
            }

            cout << (num >= 0 ? "YES" : "NO") << endl;
        }
        
    }

    return 0;
}
