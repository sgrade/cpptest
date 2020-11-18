// A. Kuroni and the Gifts

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n], b[n];
        for (auto &el: a) cin >> el;
        sort(a, a+n);
        for (auto &el: b) cin >> el;
        sort(b, b+n);

        for (auto el: a) cout << el << ' ';
        cout << endl;
        for (auto el: b) cout << el << ' ';
        cout << endl;
    }

    return 0;
}
