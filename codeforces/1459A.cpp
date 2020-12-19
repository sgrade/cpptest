// A. Red-Blue Shuffle
// NOT FINISHED

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

        sort(r, r+n, greater<int>());
        sort(b, b+n, greater<int>());

        int rans = 0;
        int bans = 0;
        for (int ri = 0; ri < n; ++ri){
            for (int bi = 0; bi < n; ++bi){
                if (r[ri] > b[bi]){
                    ++rans;
                }
                else if (r[ri] > b[bi]){
                    ++bans;
                }
            }
        }

        if (rans > bans) cout << "RED";
        else if (rans < bans) cout << "BLUE";
        else cout << "EQUAL";
        cout << endl;

        int ans = 0;


    }

    return 0;
}
