// A. Red-Blue Shuffle

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;

        getline(cin >> ws, s);
        int r[n];
        for (int i = 0; i < n; ++i){
            r[i] = (int)s[i] - 48;
        }
        
        getline(cin >> ws, s);
        int b[n];
        for (int i = 0; i < n; ++i){
            b[i] = (int)s[i] - 48;
        }

        int rans = 0;
        int bans = 0;
        for (int i = 0; i < n; ++i){
            if (r[i] > b[i]) ++rans;
            else if (r[i] < b[i]) ++bans;
        }

        if (rans > bans) cout << "RED";
        else if (rans < bans) cout << "BLUE";
        else cout << "EQUAL";
        cout << endl;
    }

    return 0;
}
