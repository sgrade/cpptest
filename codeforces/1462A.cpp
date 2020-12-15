// A. Favorite Sequence

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &el: v) cin >> el;

        int i = 0;
        for (; i < n / 2; ++i){
            cout << v[i] << ' ' << v[n-1-i] << ' ';
        }
        if (n % 2 != 0) cout << v[i];
        cout << endl;

    }

    return 0;
}
