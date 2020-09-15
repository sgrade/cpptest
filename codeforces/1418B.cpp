// B. Negative Prefixes

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        int a[n];
        int l[n];
        for (int i=0; i<n; ++i){
            cin >> a[i];
        }
        for (int i=0; i<n; ++i){
            cin >> l[i];
        }

        // Editorial - https://codeforces.com/blog/entry/82673
        vector<int> v;
        for (int i=0; i<n; ++i){
            if (l[i] == 0) v.push_back(a[i]);
        }
        sort(v.rbegin(), v.rend());

        int count = 0;
        for (int i=0; i<n; ++i){
            if (l[i] == 1) cout << a[i] << " ";
            else {
                cout << v[count++] << " ";
            }
        }

        cout << endl;

    }

    return 0;
}