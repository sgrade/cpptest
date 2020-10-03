// B. Kind Anton

#include <iostream>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n], b[n];
        for (int i=0; i<n; ++i) cin >> a[i];
        for (int i=0; i<n; ++i) cin >> b[i];

        bool ans = true;

        // first element
        if (a[0] != b[0]) ans = false;

        // second and following elements
        map<int, bool> mp = {
            {-1, false},
            {0, true},
            {1, false}
        };

        for (int i=1; i<n && ans; ++i){

            // Check if there is no need to continue search 
            // (-1, 0, 1 are found - everything can be constructed from them)
            if (mp[-1] && mp[1]) break;

            for (int j=0; j<i; ++j){

                mp[a[j]] = true;

                if (b[i] < a[i] && mp[-1]) break;
                else if (b[i] > a[i] && mp[1]) break;
                else if (b[i] == a[i]) break;
                else if (j == i-1){
                    ans = false;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}